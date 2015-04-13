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

Instructor::Instructor(const char* filePath){
    Instructor::_pc = 0;
    _filePath = filePath;
}

void Instructor::ExcuteInstruction(){
    LoadInstruction();
    
    setStackPointer(0x8000);
    setReturnAddress(0xffffffff);
    
//    for(auto iter = Instructor::_memory.begin(); iter != Instructor::_memory.end(); iter ++){
//        printf("%x\n",*iter);
//    }

    
    
    int count = 1;
    while (Instructor::_pc != 0xffffffff) {
        //print Cycles
        char cycleString[30];
        sprintf(cycleString, "Cycle : %d\nPC : %d \n",count,Instructor::_pc);
        AppendLog(cycleString);
        
        unsigned int inst = Fetch();
        Instruction* instruction = Decode(inst);
        bool branchChk = Excute(instruction);
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
    return Instructor::_memory[_pc / 4];
}

bool Instructor::Excute(Instruction* inst){
    if(inst == NULL)
        return false;
    bool branchChk = inst->Excution();
    return branchChk;
}


void Instructor::LoadInstruction(){
    
    FILE* fp = fopen(_filePath, "r");
    
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
    unsigned int opcode = (inst & 0xfc000000) >> 26;
    unsigned int rs     = (inst & 0x03e00000) >> 21;
    unsigned int rt     = (inst & 0x001f0000) >> 16;
    unsigned int rd     = (inst & 0x0000f800) >> 11;
    unsigned int shamt  = (inst & 0x000007c0) >> 6;
    unsigned int funct  = (inst & 0x0000002f);

    if(opcode == 0){
        //R_Instruction
        if(funct == Funct::Add)
            return new Add(rs, rt, rd);
        else if(funct == Funct::AddUnsigned)
            return new AddUnsigned(rs, rt, rd);
        else if(funct == Funct::And)
            return new And(rs, rt, rd);
        else if(funct == Funct::JumpRegister)
            return new JumpRegister(rs);
        else if(funct == Funct::Nor)
            return new Nor(rs, rt, rd);
        else if(funct == Funct::Or)
            return new Or(rs, rt ,rd);
        else if(funct == Funct::SetLessThan)
            return new SetLessThan(rs, rt ,rd);
        else if(funct == Funct::SetLessThanUnsigned)
            return new SetLessThanUnsigned(rs, rt ,rd);
        else if(funct == Funct::ShiftLeftLogical)
            return new ShiftLeftLogical(rt, rd, shamt);
        else if(funct == Funct::ShiftRightLogical)
            return new ShiftRightLogical(rt, rd, shamt);
        else if(funct == Funct::Subtract)
            return new Subtract(rs, rt, rd);
        else if(funct == Funct::SubtractUnsigned)
            return new SubtractUnsigned(rs, rt, rd);
        else if(funct == Funct::Divide)
            return new Divide(rs, rt);
        else if(funct == Funct::DivideUnsigned)
            return new DivideUnsigned(rs, rt);
        else if(funct == Funct::MoveFromHi)
            return new MoveFromHi(rd);
        else if(funct == Funct::MoveFromLo)
            return new MoveFromLo(rd);
        else if(funct == Funct::MoveToHi)
            return new MoveToHi(rs);
        else if(funct == Funct::MoveToLo)
            return new MoveToLo(rs);
        else if(funct == Funct::Multiply)
            return new Multiply(rs, rt);
        else if(funct == Funct::MultiplyUnsigned)
            return new MultiplyUnsigned(rs, rt);
    }
    else if(opcode == Opcode::Jump || opcode == Opcode::JumpAndLink){
        //J_Instruction
        unsigned int address = inst & 0x03ffffff;
        unsigned int pc = Instructor::_pc + 4;
        unsigned int jumpAddr = (pc & 0xf0000000) | (address << 2);
        
        if(opcode == Opcode::Jump)
            return new Jump(jumpAddr);
        else if(opcode == Opcode::JumpAndLink)
            return new JumpAndLink(jumpAddr);
    }
    else {
        //I_Instruction + Extra R_Instruction
        unsigned int immediate  = (inst & 0x0000ffff);
        unsigned int sign       = immediate >> 15;
        unsigned int signExtimm = GetExtension(sign, immediate);
        unsigned int zeroExtimm = GetExtension(0, immediate);
        unsigned int branchAddr = GetExtension(sign, immediate) << 2;
        
        if(opcode == Opcode::AddImmediate)
            return new AddImmediate(rs, rt, signExtimm);
        else if(opcode == Opcode::AddImmediateUnsigned)
            return new AddImmediateUnsigned(rs, rt, signExtimm);
        else if(opcode == Opcode::AndImmediate)
            return new AndImmediate(rs, rt, zeroExtimm);
        else if(opcode == Opcode::BranchOnEqual)
            return new BranchOnEqual(rs, rt, branchAddr);
        else if(opcode == Opcode::BranchOnNotEqual)
            return new BranchOnNotEqual(rs, rt, branchAddr);
        else if(opcode == Opcode::LoadByteUnsigned)
            return new LoadByteUnsigned(rs, rt, signExtimm);
        else if(opcode == Opcode::LoadHalfwordUnsigned)
            return new LoadHalfwordUnsigned(rs, rt, signExtimm);
        else if(opcode == Opcode::LoadLinked)
            return new LoadLinked(rs, rt, signExtimm);
        else if(opcode == Opcode::LoadUpperImmediate)
            return new LoadUpperImmediate(rt, immediate);
        else if(opcode == Opcode::LoadWord)
            return new LoadWord(rs, rt, signExtimm);
        else if(opcode == Opcode::OrImmediate)
            return new OrImmediate(rs, rt, zeroExtimm);
        else if(opcode == Opcode::SetLessThanImmediate)
            return new SetLessThanImmediate(rs, rt, signExtimm);
        else if(opcode == Opcode::SetLessThanImmediateUnsigned)
            return new SetLessThanImmediateUnsigned(rs, rt, signExtimm);
        else if(opcode == Opcode::StoreByte)
            return new StoreByte(rs, rt, signExtimm);
        else if(opcode == Opcode::StoreConditional)
            return new StoreConditional(rs, rt, signExtimm);
        else if(opcode == Opcode::StoreHalfWord)
            return new StoreHalfword(rs, rt, signExtimm);
        else if(opcode == Opcode::StoreWord || opcode == Opcode::StoreConditional)
            return new StoreWord(rs, rt, signExtimm);
        else if(opcode == Opcode::Multiply32Bit && opcode == Opcode::Multiply32Bit)
            return new Multiply32Bit(rs,rt,rd);
        }
    
    return NULL;
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



