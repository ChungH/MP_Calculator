//
//  Instructor.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#include <fstream>
#include "Instructor.h"
#include "InstructionSet.h"
#include "Add.h"
#include "And.h"
#include "Branch.h"
#include "Jump.h"
#include "Load.h"
#include "Or.h"
#include "SetLessThan.h"
#include "Shift.h"
#include "Store.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
#include "Move.h"

//Testcode

Instructor::Instructor(const char* filePath){
    Instructor::_pc = 0;
    _filePath = filePath;
}

void Instructor::ExecuteInstruction(){
    LoadInstruction();
    
    setStackPointer(0x8000);
    setReturnAddress(0xffffffff);
    
    for(auto iter = Instructor::_memory.begin(); iter != Instructor::_memory.end(); iter ++){
        printf("%x\n",*iter);
    }
    _WBInst = _MEMInst = _EXEInst = NULL;
    
    
    
    int count = 1;
    while (Instructor::_pc != 0xffffffff) {
        //print Cycles
        char cycleString[30];
        sprintf(cycleString, "Cycle : %d\nPC : %d \n",count,Instructor::_pc);
        AppendLog(cycleString);
        
        bool branchChk;
        
        //WriteBack
        if(_WBInst != NULL)
            _WBInst->WriteBack();


        //MemoryAccess
        if(_MEMInst != NULL)
            _MEMInst->MemoryAccess();

        
        //Execute
        if(_EXEInst != NULL){
            DataForwarding();
            branchChk = _EXEInst->Execution();
        }
        else
            branchChk = false;
        
        //Instruction Switching
        delete _WBInst;
        _WBInst = _MEMInst;
        _MEMInst = _EXEInst;
        _EXEInst = _DecodeInst;
        
        //Decode
        _DecodeInst= Decode(_inst);
        
        //Fetch
        _inst = Fetch();
        
        if (!branchChk) {
            _pc += 4;
        }
        count++;
    }
    
    char logBuf[20];
    sprintf(logBuf, "Result Value \nR2 : %d",Instructor::_register[2]);
    Instructor::AppendLog(logBuf);
    
}
unsigned int Instructor::Fetch(){
    if(Instructor::_pc == 0xffffffff)
        return 0;
    return Instructor::_memory[_pc / 4];
}

void Instructor::LoadInstruction(){
    
    FILE* fp = fopen("/Users/ChungH/Desktop/add.bin", "r");
 //   FILE* fp = fopen(_filePath, "r");
    
    int i = 0;
    char tmp[10];
    int count = 0;
    
    while(!feof(fp)){
        tmp[count] = fgetc(fp);
        if(*(fp->_p) ==' ' || *(fp->_p) == '\n')
            fp->_p++;
        count++;
        if(count == 8){
            tmp[count] = '\0';
            std::istringstream(tmp) >> std::hex >> Instructor::_memory[i];
         //   printf("%x\n",Instructor::_memory[i]);
            count = 0;
            i++;
        }
    }
}

Instruction* Instructor::Decode(unsigned int const inst){
    //Decoding Instruction
    if(inst == 0)
        return NULL;
    Instruction* instruction;
    unsigned int opcode = (inst & 0xfc000000) >> 26;
    unsigned int rs     = (inst & 0x03e00000) >> 21;
    unsigned int rt     = (inst & 0x001f0000) >> 16;
    unsigned int rd     = (inst & 0x0000f800) >> 11;
    unsigned int shamt  = (inst & 0x000007c0) >> 6;
    unsigned int funct  = (inst & 0x0000003f);
    
    
    unsigned int rsData = Instructor::GetDataFromRegister(rs);
    unsigned int rtData = Instructor::GetDataFromRegister(rt);

    if(opcode == 0){
        //R_Instruction
        if(funct == Funct::Add)
            instruction = new Add(rs, rt, rd, rsData, rtData);
        else if(funct == Funct::AddUnsigned)
            instruction = new AddUnsigned(rs, rt, rd, rsData, rtData);
        else if(funct == Funct::And)
            instruction = new And(rs, rt, rd,rsData, rtData);
        else if(funct == Funct::JumpRegister)
            instruction = new JumpRegister(rs, rsData);
        else if(funct == Funct::Nor)
            instruction = new Nor(rs, rt, rd,rsData,rtData);
        else if(funct == Funct::Or)
            instruction = new Or(rs, rt ,rd,rsData, rtData);
        else if(funct == Funct::SetLessThan)
            instruction = new SetLessThan(rs, rt ,rd, rsData, rtData);
        else if(funct == Funct::SetLessThanUnsigned)
            instruction = new SetLessThanUnsigned(rs, rt ,rd, rsData, rtData);
        else if(funct == Funct::ShiftLeftLogical)
            instruction = new ShiftLeftLogical(rt, rd, shamt, rtData);
        else if(funct == Funct::ShiftRightLogical)
            instruction = new ShiftRightLogical(rt, rd, shamt, rtData);
        else if(funct == Funct::Subtract)
            instruction = new Subtract(rs, rt, rd, rsData, rtData);
        else if(funct == Funct::SubtractUnsigned)
            instruction = new SubtractUnsigned(rs, rt, rd, rsData, rtData);
        else if(funct == Funct::Divide)
            instruction = new Divide(rs, rt, rsData, rtData);
        else if(funct == Funct::DivideUnsigned)
            instruction = new DivideUnsigned(rs, rt, rsData, rtData);
        else if(funct == Funct::MoveFromHi)
            instruction = new MoveFromHi(rd);
        else if(funct == Funct::MoveFromLo)
            instruction = new MoveFromLo(rd);
        else if(funct == Funct::MoveToHi)
            instruction = new MoveToHi(rs, rsData);
        else if(funct == Funct::MoveToLo)
            instruction = new MoveToLo(rs, rsData);
        else if(funct == Funct::Multiply)
            instruction = new Multiply(rs, rt, rsData, rtData);
        else if(funct == Funct::MultiplyUnsigned)
            instruction = new MultiplyUnsigned(rs, rt, rsData, rtData);
    }
    else if(opcode == Opcode::Jump || opcode == Opcode::JumpAndLink){
        //J_Instruction
        unsigned int address = inst & 0x03ffffff;
        unsigned int pc = Instructor::_pc + 4;
        unsigned int jumpAddr = (pc & 0xf0000000) | (address << 2);
        
        if(opcode == Opcode::Jump)
            instruction = new Jump(jumpAddr);
        else if(opcode == Opcode::JumpAndLink)
            instruction = new JumpAndLink(jumpAddr);
    }
    else {
        //I_Instruction + Extra R_Instruction
        unsigned int immediate  = (inst & 0x0000ffff);
        unsigned int sign       = immediate >> 15;
        unsigned int signExtimm = GetExtension(sign, immediate);
        unsigned int zeroExtimm = GetExtension(0, immediate);
        unsigned int branchAddr = GetExtension(sign, immediate) << 2;
        
        if(opcode == Opcode::AddImmediate)
            instruction = new AddImmediate(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::AddImmediateUnsigned)
            instruction = new AddImmediateUnsigned(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::AndImmediate)
            instruction = new AndImmediate(rs, rt, zeroExtimm,rsData);
        else if(opcode == Opcode::BranchOnEqual)
            instruction = new BranchOnEqual(rs, rt, branchAddr, rsData, rtData);
        else if(opcode == Opcode::BranchOnNotEqual)
            instruction = new BranchOnNotEqual(rs, rt, branchAddr, rsData, rtData);
        else if(opcode == Opcode::LoadByteUnsigned)
            instruction = new LoadByteUnsigned(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::LoadHalfwordUnsigned)
            instruction = new LoadHalfwordUnsigned(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::LoadLinked)
            instruction = new LoadLinked(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::LoadUpperImmediate)
            instruction = new LoadUpperImmediate(rt, immediate);
        else if(opcode == Opcode::LoadWord)
            instruction = new LoadWord(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::OrImmediate)
            instruction = new OrImmediate(rs, rt, zeroExtimm, rsData);
        else if(opcode == Opcode::SetLessThanImmediate)
            instruction = new SetLessThanImmediate(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::SetLessThanImmediateUnsigned)
            instruction = new SetLessThanImmediateUnsigned(rs, rt, signExtimm, rsData);
        else if(opcode == Opcode::StoreByte)
            instruction = new StoreByte(rs, rt, signExtimm, rsData, rtData);
        else if(opcode == Opcode::StoreConditional)
            instruction = new StoreConditional(rs, rt, signExtimm, rsData, rtData);
        else if(opcode == Opcode::StoreHalfWord)
            instruction = new StoreHalfword(rs, rt, signExtimm, rsData, rtData);
        else if(opcode == Opcode::StoreWord || opcode == Opcode::StoreConditional)
            instruction = new StoreWord(rs, rt, signExtimm, rsData, rtData);
        else if(opcode == Opcode::Multiply32Bit && opcode == Opcode::Multiply32Bit)
            instruction = new Multiply32Bit(rs,rt,rd, rsData, rtData);
        }
    
    return instruction;
}

unsigned int Instructor::GetDataFromMemory(int index){
    return Instructor::_memory[index];
}

void Instructor::SetDataToMemory(int index, unsigned int val){
    Instructor::_memory[index] = val;
}

void Instructor::SetDataToRegister(int index, unsigned int val){
    Instructor::_register[index] = val;
}
unsigned int Instructor::GetDataFromRegister(int index){
    return Instructor::_register[index];
}

unsigned int Instructor::GetExtension(unsigned int sign, unsigned int immediate){
    unsigned int ret = 0;
    if(sign == 0){
        ret = 0x00000000 | immediate;
    }
    else if(sign == 1) {
        ret = 0xffff0000 | immediate;
    }
    return ret;
}

void Instructor::AppendLog(const std::string& log){
    Instructor::_logBuffer += log;
}
void Instructor::PrintLog(const std::string& path){
    std::ofstream outFp(path);
    outFp.write(Instructor::_logBuffer.c_str(),Instructor::_logBuffer.size());
}

void Instructor::DataForwarding(){
    if(_EXEInst -> _instType == Instructiontype::J_Type)
        return;
    //init
    _MEM_rs = _MEM_rt = _WB_rs = _WB_rt = false;
    
    //Dependency Check
    DependencyChk();
    
    //Data Forwarding
    //rs Forwarding
    if(_MEM_rs && _WB_rs){
        if(_MEMInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rsData = _MEMInst->_rdData;
        else
            _EXEInst->_rsData = _MEMInst->_rtData;
    }
    else if(_MEM_rs && !_WB_rs){
        if(_MEMInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rsData = _MEMInst->_rdData;
        else
            _EXEInst->_rsData = _MEMInst->_rtData;
    }
    else if(!_MEM_rs && _WB_rs){
        if(_WBInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rsData = _WBInst->_rdData;
        else
            _EXEInst->_rsData = _WBInst->_rtData;
    }
    
    //rt Forwarding
    if(_MEM_rt && _WB_rt){
        if(_MEMInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rtData = _MEMInst->_rdData;
        else
            _EXEInst->_rtData = _MEMInst->_rtData;
    }
    else if(_MEM_rt && !_WB_rt){
        if(_MEMInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rtData = _MEMInst->_rdData;
        else
            _EXEInst->_rtData = _MEMInst->_rtData;
    }
    else if(!_MEM_rt && _WB_rt){
        if(_WBInst->_instType ==Instructiontype::R_Type)
            _EXEInst->_rtData = _WBInst->_rdData;
        else
            _EXEInst->_rtData = _WBInst->_rtData;
    }
    
    
    

    
}

void Instructor::DependencyChk(){
    //EXE - MEM dependency
    if(_MEMInst != NULL){
        //rs - MEM dependency
        if(_MEMInst->_writeChk  && _MEMInst->_instType == Instructiontype::R_Type && _MEMInst->_rd == _EXEInst->_rs)
            _MEM_rs = true;
        else if(_MEMInst->_writeChk  && _MEMInst->_instType == Instructiontype::I_Type && _MEMInst->_rt == _EXEInst->_rs)
            _MEM_rs = true;
        
        //rt - MEM dependency
        if(_MEMInst->_writeChk  && _MEMInst->_instType == Instructiontype::R_Type && _MEMInst->_rd == _EXEInst->_rt)
            _MEM_rt = true;
        else if(_MEMInst->_writeChk  &&_MEMInst->_instType == Instructiontype::I_Type && _MEMInst->_rt == _EXEInst->_rt)
            _MEM_rt = true;
    }
    
    //EXE - WB dependency
    if(_WBInst != NULL) {
        //rs - WB dependency
        if(_WBInst->_writeChk  && _WBInst->_instType == Instructiontype::R_Type && _WBInst->_rd == _EXEInst->_rs)
            _WB_rs = true;
        else if(_WBInst->_writeChk  && _WBInst->_instType == Instructiontype::I_Type && _WBInst->_rt == _EXEInst->_rs)
            _WB_rs = true;
        
        //rt - WB dependency
        if(_WBInst->_writeChk  && _WBInst->_instType == Instructiontype::R_Type && _WBInst->_rd == _EXEInst->_rt)
            _WB_rt = true;
        else if(_WBInst->_writeChk  && _WBInst->_instType == Instructiontype::I_Type && _WBInst->_rt == _EXEInst->_rt)
            _WB_rt = true;
    }
}

