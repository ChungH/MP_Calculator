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
    Instructor::_filePath = filePath;
    Instructor::_lastBranch = 1;
    Instructor::_predictionHit = 0;
    Instructor::_predictionMiss= 0;
    Instructor::_cache = Cache();
}

void Instructor::ExecuteInstruction(){
    LoadInstruction();
    
    setStackPointer(0x40000);
    setReturnAddress(0xffffffff);
    
    for(auto iter = Instructor::_memory.begin(); iter != Instructor::_memory.end(); iter ++){
        printf("%x\n",*iter);
    }
    _WBInst = _MEMInst = _EXEInst = NULL;
    _fetchInst = 0;
    
    int count = 1;

    while (Instructor::_pc != 0xffffffff || _WBInst != NULL || _MEMInst != NULL || _EXEInst != NULL) {
        //print Cycles
        char cycleString[30];
        sprintf(cycleString, "%d,",count);
        AppendLog(cycleString);
        
        
        _branchChk = false;
        _jumpChk = false;
        _MEM_rs = _MEM_rt = _WB_rs = _WB_rt = false;
        
        //WriteBack
        if(_WBInst != NULL)
            _WBInst->WriteBack();
        else
            Instructor::AppendLog("0,");


        //MemoryAccess
        if(_MEMInst != NULL)
            _MEMInst->MemoryAccess();
        else
            Instructor::AppendLog("0,");
        
        //Execute
        if(_EXEInst != NULL){
            DataForwarding();
            _branchChk = _EXEInst->Execution();
        }
        else
            Instructor::AppendLog("0,0,0,");
        
        if(_branchChk){
            Instructor::AppendLog("1,");
            _DECInst = NULL;
            _fetchInst = 0;
        }
        else
            Instructor::AppendLog("0,");
        
        //Decode
        _DECInst = Decode(_fetchInst);
        
        //Fetch
        _fetchInst = Fetch();
        
        //Instruction Switching
        delete _WBInst;
        _WBInst = _MEMInst;
        _MEMInst = _EXEInst;
        _EXEInst = _DECInst;
        
        if (Instructor::_pc == 0xffffffff) {
            Instructor::AppendLog("-1");
        }
        else{
            sprintf(cycleString, "%d",Instructor::_pc/4);
            AppendLog(cycleString);
        }
        
        if(_pc != 0xffffffff)
           _pc += 4;

        
        Instructor::AppendLog("\n");
        count++;
    }
    
}
unsigned int Instructor::Fetch(){
    if(Instructor::_pc == 0xffffffff){
        _jumpChk = true;
        Instructor::AppendLog("0,");
        return 0;
    }
    unsigned int inst = Instructor::GetDataFromCache(Instructor::_pc);
    DecodeInstName(inst);
    return inst;
}


/*void Instructor::LoadInstruction()
 {
    std::string path = "/Users/ChungH/Desktop/Mips_Simulator/input4/input4/input4.bin";
	std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);

     long long length = file.tellg();
	file.seekg(0, file.beg);
 
	unsigned char* buffer = new unsigned char[length];
	{
        file.read((char*)buffer, length);
        std::copy((unsigned int*)buffer, (unsigned int*)&buffer[length], _memory.begin());
	}
	delete buffer;
 
 file.close();
 
	auto IsLittleEndian = []()
	{
 union{
 int a;
 char b;
 }Test;
 
 Test.a = 1;
 return Test.b;
	};
	auto LittleEndianToBigEndian = [](unsigned int x)
	{
 return x = ( x >> 24 ) | (( x << 8) & 0x00ff0000 )| ((x >> 8) & 0x0000ff00) | ( x << 24);
	};
 
	if(IsLittleEndian())
	{
 
 for(int i=0; i<length / 4; ++i)
     _memory[i] = LittleEndianToBigEndian(_memory[i]);
	}
 }
*/

void Instructor::LoadInstruction(){
    
    FILE* fp = fopen("/Users/ChungH/Desktop/Mips_Simulator/Sample/10fac.bin", "r");
    //위의 경로를 변경하시면 됩니다.
    
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
            printf("%x\n",Instructor::_memory[i]);
            count = 0;
            i++;
        }
    }
}

Instruction* Instructor::Decode(unsigned int const inst){
    //Decoding Instruction
    if(inst == 0){
        Instructor::AppendLog("0,");
        return NULL;
    }
    Instruction* instruction;
    unsigned int opcode = (inst & 0xfc000000) >> 26;
    unsigned int rs     = (inst & 0x03e00000) >> 21;
    unsigned int rt     = (inst & 0x001f0000) >> 16;
    unsigned int rd     = (inst & 0x0000f800) >> 11;
    unsigned int shamt  = (inst & 0x000007c0) >> 6;
    unsigned int funct  = (inst & 0x0000003f);
    unsigned int pc = Instructor::_pc - 4;
    
    
    unsigned int rsData = Instructor::GetDataFromRegister(rs);
    unsigned int rtData = Instructor::GetDataFromRegister(rt);

    if(opcode == 0){
        //R_Instruction
        if(funct == Funct::Add){
            instruction = new Add(rs, rt, rd, rsData, rtData);
            Instructor::AppendLog("ADD,");
        }
        else if(funct == Funct::AddUnsigned){
            instruction = new AddUnsigned(rs, rt, rd, rsData, rtData);
            Instructor::AppendLog("ADDU,");
        }
        else if(funct == Funct::And){
            instruction = new And(rs, rt, rd,rsData, rtData);
            Instructor::AppendLog("AND,");
        }
        else if(funct == Funct::JumpRegister){
            instruction = new JumpRegister(rs, rsData);
            Instructor::_pc = rsData;
            _jumpChk = true;
            Instructor::AppendLog("JR,");
        }
        else if(funct == Funct::Nor){
            instruction = new Nor(rs, rt, rd,rsData,rtData);
            Instructor::AppendLog("NOR,");
        }
        else if(funct == Funct::Or){
            instruction = new Or(rs, rt ,rd,rsData, rtData);
            Instructor::AppendLog("OR,");
        }
        else if(funct == Funct::SetLessThan){
            instruction = new SetLessThan(rs, rt ,rd, rsData, rtData);
            Instructor::AppendLog("SLT,");
        }
        else if(funct == Funct::SetLessThanUnsigned){
            instruction = new SetLessThanUnsigned(rs, rt ,rd, rsData, rtData);
            Instructor::AppendLog("SLTU,");
        }
        else if(funct == Funct::ShiftLeftLogical){
            instruction = new ShiftLeftLogical(rt, rd, shamt, rtData);
            Instructor::AppendLog("SLL,");
        }
        else if(funct == Funct::ShiftRightLogical){
            instruction = new ShiftRightLogical(rt, rd, shamt, rtData);
            Instructor::AppendLog("SRL,");
        }
        else if(funct == Funct::Subtract){
            instruction = new Subtract(rs, rt, rd, rsData, rtData);
            Instructor::AppendLog("SUB,");
        }
        else if(funct == Funct::SubtractUnsigned){
            instruction = new SubtractUnsigned(rs, rt, rd, rsData, rtData);
            Instructor::AppendLog("SUBU,");
        }
        else if(funct == Funct::Divide){
            instruction = new Divide(rs, rt, rsData, rtData);
            Instructor::AppendLog("DIV,");
        }
        else if(funct == Funct::DivideUnsigned){
            instruction = new DivideUnsigned(rs, rt, rsData, rtData);
            Instructor::AppendLog("DIVU,");
        }
        else if(funct == Funct::MoveFromHi){
            instruction = new MoveFromHi(rd);
            Instructor::AppendLog("MFH,");
        }
        else if(funct == Funct::MoveFromLo){
            instruction = new MoveFromLo(rd);
            Instructor::AppendLog("MFL,");
        }
        else if(funct == Funct::MoveToHi){
            instruction = new MoveToHi(rs, rsData);
            Instructor::AppendLog("MTH,");
        }
        else if(funct == Funct::MoveToLo){
            instruction = new MoveToLo(rs, rsData);
            Instructor::AppendLog("MTL,");
        }
        else if(funct == Funct::Multiply){
            instruction = new Multiply(rs, rt, rsData, rtData);
            Instructor::AppendLog("MULT,");
        }
        else if(funct == Funct::MultiplyUnsigned){
            instruction = new MultiplyUnsigned(rs, rt, rsData, rtData);
            Instructor::AppendLog("MULTU,");
        }
    }
    else if(opcode == Opcode::Jump || opcode == Opcode::JumpAndLink){
        //J_Instruction
        unsigned int address = inst & 0x03ffffff;
        unsigned int jumpAddr = (pc & 0xf0000000) | (address << 2);
        
        if(opcode == Opcode::Jump){
            instruction = new Jump(jumpAddr);
            Instructor::_pc = jumpAddr;
//            _fetchInst = 0;
            _jumpChk = true;
            Instructor::AppendLog("J,");
        }
        else if(opcode == Opcode::JumpAndLink){
            instruction = new JumpAndLink(jumpAddr, pc);
            Instructor::_pc = jumpAddr;
            _jumpChk = true;
            Instructor::AppendLog("JAL,");
        }
    }
    else {
        //I_Instruction + Extra R_Instruction
        unsigned int immediate  = (inst & 0x0000ffff);
        unsigned int sign       = immediate >> 15;
        unsigned int signExtimm = GetExtension(sign, immediate);
        unsigned int zeroExtimm = GetExtension(0, immediate);
        unsigned int branchAddr = GetExtension(sign, immediate) << 2;
        
        if(opcode == Opcode::AddImmediate){
            instruction = new AddImmediate(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("ADDI,");
        }
        else if(opcode == Opcode::AddImmediateUnsigned){
            instruction = new AddImmediateUnsigned(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("ADDIU,");
        }
        else if(opcode == Opcode::AndImmediate){
            instruction = new AndImmediate(rs, rt, zeroExtimm,rsData);
            Instructor::AppendLog("ANDI,");
        }
        else if(opcode == Opcode::BranchOnEqual){
            if(Instructor::_lastBranch <= 1){
                instruction = new BranchOnEqual(rs, rt, branchAddr, rsData, rtData, pc);
                Instructor::_pc = pc + 4 + branchAddr;
                _jumpChk = true;
                Instructor::AppendLog("BEQ,");
            }
            else{
                instruction = new BranchOnEqual(rs, rt, branchAddr, rsData, rtData, pc);
                _jumpChk = false;
                Instructor::AppendLog("BEQ,");
            }
        }
        else if(opcode == Opcode::BranchOnNotEqual){
            if(Instructor::_lastBranch <= 1){
                instruction = new BranchOnNotEqual(rs, rt, branchAddr, rsData, rtData, pc);
                Instructor::_pc = pc + 4 + branchAddr;
                _jumpChk = true;
                Instructor::AppendLog("BNE,");
            }
            else{
                instruction = new BranchOnNotEqual(rs, rt, branchAddr, rsData, rtData, pc);
                _jumpChk = false;
                Instructor::AppendLog("BNE,");
            }
        }
        else if(opcode == Opcode::LoadByteUnsigned){
            instruction = new LoadByteUnsigned(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("LBU,");
        }
        else if(opcode == Opcode::LoadHalfwordUnsigned){
            instruction = new LoadHalfwordUnsigned(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("LHU,");
        }
        else if(opcode == Opcode::LoadLinked){
            instruction = new LoadLinked(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("LL,");
        }
        else if(opcode == Opcode::LoadUpperImmediate){
            instruction = new LoadUpperImmediate(rt, immediate);
            Instructor::AppendLog("LUI,");
        }
        else if(opcode == Opcode::LoadWord){
            instruction = new LoadWord(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("LW,");
        }
        else if(opcode == Opcode::OrImmediate){
            instruction = new OrImmediate(rs, rt, zeroExtimm, rsData);
            Instructor::AppendLog("ORI,");
        }
        else if(opcode == Opcode::SetLessThanImmediate){
            instruction = new SetLessThanImmediate(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("SLTI,");
        }
        else if(opcode == Opcode::SetLessThanImmediateUnsigned){
            instruction = new SetLessThanImmediateUnsigned(rs, rt, signExtimm, rsData);
            Instructor::AppendLog("SLTIU,");
        }
        else if(opcode == Opcode::StoreByte){
            instruction = new StoreByte(rs, rt, signExtimm, rsData, rtData);
            Instructor::AppendLog("SB,");
        }
        else if(opcode == Opcode::StoreConditional){
            instruction = new StoreConditional(rs, rt, signExtimm, rsData, rtData);
            Instructor::AppendLog("SC,");
        }
        else if(opcode == Opcode::StoreHalfWord){
            instruction = new StoreHalfword(rs, rt, signExtimm, rsData, rtData);
            Instructor::AppendLog("SH,");
        }
        else if(opcode == Opcode::StoreWord || opcode == Opcode::StoreConditional){
            instruction = new StoreWord(rs, rt, signExtimm, rsData, rtData);
            Instructor::AppendLog("SW,");
        }
        else if(opcode == Opcode::Multiply32Bit){
            instruction = new Multiply32Bit(rs,rt,rd, rsData, rtData);
            Instructor::AppendLog("MULT32,");
            }
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
    if(_EXEInst -> _instType == Instructiontype::J_Type){
        Instructor::AppendLog("0,0,");
        return;
    }
    //init
    
    //Dependency Check
    DependencyChk();
    
    //Dependency Log
    
    //Data Forwarding
    //rs Forwarding
    if(_MEM_rs && _WB_rs){
        if(_MEMInst->_instType ==Instructiontype::R_Type || _MEMInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rsData = _MEMInst->_rdData;
        else
            _EXEInst->_rsData = _MEMInst->_rtData;
        Instructor::AppendLog("1,");
    }
    else if(_MEM_rs && !_WB_rs){
        if(_MEMInst->_instType ==Instructiontype::R_Type || _MEMInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rsData = _MEMInst->_rdData;
        else
            _EXEInst->_rsData = _MEMInst->_rtData;
        Instructor::AppendLog("1,");
    }
    else if(!_MEM_rs && _WB_rs){
        if(_WBInst->_instType ==Instructiontype::R_Type|| _WBInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rsData = _WBInst->_rdData;
        else
            _EXEInst->_rsData = _WBInst->_rtData;
        Instructor::AppendLog("2,");
    }
    else
        Instructor::AppendLog("0,");
    
    //rt Forwarding
    if(_MEM_rt && _WB_rt){
        if(_MEMInst->_instType ==Instructiontype::R_Type || _MEMInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rtData = _MEMInst->_rdData;
        else
            _EXEInst->_rtData = _MEMInst->_rtData;
        Instructor::AppendLog("1,");
    }
    else if(_MEM_rt && !_WB_rt){
        if(_MEMInst->_instType ==Instructiontype::R_Type || _MEMInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rtData = _MEMInst->_rdData;
        else
            _EXEInst->_rtData = _MEMInst->_rtData;
        Instructor::AppendLog("1,");
    }
    else if(!_MEM_rt && _WB_rt){
        if(_WBInst->_instType ==Instructiontype::R_Type || _WBInst->_instType == Instructiontype::J_Type)
            _EXEInst->_rtData = _WBInst->_rdData;
        else
            _EXEInst->_rtData = _WBInst->_rtData;
        Instructor::AppendLog("2,");
    }
    else
        Instructor::AppendLog("0,");
    
}

void Instructor::DependencyChk(){
    //EXE - MEM dependency
    if(_MEMInst != NULL){
        //rs - MEM dependency
        if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::R_Type && _MEMInst->_rd == _EXEInst->_rs)
            _MEM_rs = true;
        else if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::I_Type && _MEMInst->_rt == _EXEInst->_rs)
            _MEM_rs = true;
        else if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::J_Type && _MEMInst->_rd == _EXEInst->_rs)
            _MEM_rs = true;
        
        //rt - MEM dependency
        if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::R_Type && _MEMInst->_rd == _EXEInst->_rt)
            _MEM_rt = true;
        else if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::I_Type && _MEMInst->_rt == _EXEInst->_rt)
            _MEM_rt = true;
        else if(_MEMInst->_writeChk && _MEMInst->_instType == Instructiontype::J_Type && _MEMInst->_rd == _EXEInst->_rt)
            _MEM_rt = true;
    }
    
    //EXE - WB dependency
    if(_WBInst != NULL) {
        //rs - WB dependency
        if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::R_Type && _WBInst->_rd == _EXEInst->_rs)
            _WB_rs = true;
        else if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::I_Type && _WBInst->_rt == _EXEInst->_rs)
            _WB_rs = true;
        else if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::J_Type && _WBInst->_rd == _EXEInst->_rs)
            _WB_rs = true;
        
        //rt - WB dependency
        if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::R_Type && _WBInst->_rd == _EXEInst->_rt)
            _WB_rt = true;
        else if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::I_Type && _WBInst->_rt == _EXEInst->_rt)
            _WB_rt = true;
        else if(_WBInst->_writeChk && _WBInst->_instType == Instructiontype::J_Type && _WBInst->_rd == _EXEInst->_rt)
            _WB_rt = true;
    }
}


void Instructor::DecodeInstName(unsigned int inst){
    unsigned int opcode = (inst & 0xfc000000) >> 26;
    unsigned int funct  = (inst & 0x0000003f);
    if(opcode == 0){
        //R_Instruction
        if(funct == Funct::Add){
            Instructor::AppendLog("ADD,");
        }
        else if(funct == Funct::AddUnsigned){
            Instructor::AppendLog("ADDU,");
        }
        else if(funct == Funct::And){
            Instructor::AppendLog("AND,");
        }
        else if(funct == Funct::JumpRegister){
            Instructor::AppendLog("JR,");
        }
        else if(funct == Funct::Nor){
            Instructor::AppendLog("NOR,");
        }
        else if(funct == Funct::Or){
            Instructor::AppendLog("OR,");
        }
        else if(funct == Funct::SetLessThan){
            Instructor::AppendLog("SLT,");
        }
        else if(funct == Funct::SetLessThanUnsigned){
            Instructor::AppendLog("SLTU,");
        }
        else if(funct == Funct::ShiftLeftLogical){
            Instructor::AppendLog("SLL,");
        }
        else if(funct == Funct::ShiftRightLogical){
            Instructor::AppendLog("SRL,");
        }
        else if(funct == Funct::Subtract){
            Instructor::AppendLog("SUB,");
        }
        else if(funct == Funct::SubtractUnsigned){
            Instructor::AppendLog("SUBU,");
        }
        else if(funct == Funct::Divide){
            Instructor::AppendLog("DIV,");
        }
        else if(funct == Funct::DivideUnsigned){
            Instructor::AppendLog("DIVU,");
        }
        else if(funct == Funct::MoveFromHi){
            Instructor::AppendLog("MFH,");
        }
        else if(funct == Funct::MoveFromLo){
            Instructor::AppendLog("MFL,");
        }
        else if(funct == Funct::MoveToHi){
            Instructor::AppendLog("MTH,");
        }
        else if(funct == Funct::MoveToLo){
            Instructor::AppendLog("MTL,");
        }
        else if(funct == Funct::Multiply){
            Instructor::AppendLog("MULT,");
        }
        else if(funct == Funct::MultiplyUnsigned){
            Instructor::AppendLog("MULTU,");
        }
    }
    else if(opcode == Opcode::Jump || opcode == Opcode::JumpAndLink){
        //J_Instruction
        if(opcode == Opcode::Jump){
            Instructor::AppendLog("J,");
        }
        else if(opcode == Opcode::JumpAndLink){
            Instructor::AppendLog("JAL,");
        }
    }
    else {
        //I_Instruction + Extra R_Instruction
        if(opcode == Opcode::AddImmediate){
            Instructor::AppendLog("ADDI,");
        }
        else if(opcode == Opcode::AddImmediateUnsigned){
            Instructor::AppendLog("ADDIU,");
        }
        else if(opcode == Opcode::AndImmediate){
            Instructor::AppendLog("ANDI,");
        }
        else if(opcode == Opcode::BranchOnEqual){
                Instructor::AppendLog("BEQ,");
        }
        else if(opcode == Opcode::BranchOnNotEqual){
                Instructor::AppendLog("BNE,");
        }
        else if(opcode == Opcode::LoadByteUnsigned){
            Instructor::AppendLog("LBU,");
        }
        else if(opcode == Opcode::LoadHalfwordUnsigned){
            Instructor::AppendLog("LHU,");
        }
        else if(opcode == Opcode::LoadLinked){
            Instructor::AppendLog("LL,");
        }
        else if(opcode == Opcode::LoadUpperImmediate){
            Instructor::AppendLog("LUI,");
        }
        else if(opcode == Opcode::LoadWord){
            Instructor::AppendLog("LW,");
        }
        else if(opcode == Opcode::OrImmediate){
            Instructor::AppendLog("ORI,");
        }
        else if(opcode == Opcode::SetLessThanImmediate){
            Instructor::AppendLog("SLTI,");
        }
        else if(opcode == Opcode::SetLessThanImmediateUnsigned){
            Instructor::AppendLog("SLTIU,");
        }
        else if(opcode == Opcode::StoreByte){
            Instructor::AppendLog("SB,");
        }
        else if(opcode == Opcode::StoreConditional){
            Instructor::AppendLog("SC,");
        }
        else if(opcode == Opcode::StoreHalfWord){
            Instructor::AppendLog("SH,");
        }
        else if(opcode == Opcode::StoreWord || opcode == Opcode::StoreConditional){
            Instructor::AppendLog("SW,");
        }
        else if(opcode == Opcode::Multiply32Bit){
            Instructor::AppendLog("MULT32,");
        }
    }
    
}

unsigned int Instructor::GetDataFromCache(unsigned int pc){
    unsigned int tag;
    unsigned int line;
    unsigned int offset;
    unsigned int isHit = 0;
    unsigned int inst;
    
    
    tag     = pc & Instructor::_cache._tagMask;
    line    = (pc & Instructor::_cache._lineMask) >> 6;
    offset  = pc & offsetMask;
    
    unsigned int set;
    for(set = 0; set < Sets; set++){
        isHit = _cache.HitMissCheck(set, tag, line);
        if(isHit)
            break;
    }
    
    if(isHit){
        inst = _cache.GetData(set, line, offset/4);
    }
    else{
        set = _cache.LRU(line);
        ReplaceDatainCache(pc, set, line, offset, tag);
        inst = _cache.GetData(set, line, offset/4);
    }
    
    return inst;
    
}

unsigned int Instructor::GetDataFromCache(unsigned int pc, unsigned int offset){
    unsigned int tag;
    unsigned int line;
    unsigned int data;
    bool isHit = false;
    
    tag     = pc & Instructor::_cache._tagMask;
    line    = (pc & Instructor::_cache._lineMask) >> 6;
    
    unsigned int set;
    for(set = 0; set < Sets; set++){
        isHit = _cache.HitMissCheck(set, tag, line);
        if(isHit)
            break;
    }
    
    if(isHit){
        data = _cache.GetData(set, line, offset);
    }
    else{
        set = _cache.LRU(line);
        ReplaceDatainCache(pc, set, line, offset, tag);
        data = _cache.GetData(set, line, offset);
    }
    
    return data;
}


void Instructor::SetDataToCache(unsigned int pc, unsigned int data){
    unsigned int tag;
    unsigned int line;
    unsigned int offset;
    unsigned int isHit = 0;
    
    tag     = pc & Instructor::_cache._tagMask;
    line    = (pc & Instructor::_cache._lineMask) >> 6;
    offset  = pc & offsetMask;
    
    int set;
    for(set = 0; set < Sets; set++){
        isHit = _cache.HitMissCheck(set, tag, line);
        if(isHit)
            break;
    }
    
    if(isHit){
        _cache.WriteData(set, line, offset/4, data);
    }
    else{
        set = _cache.LRU(line);
        ReplaceDatainCache(pc, set, line, offset, tag);
        _cache.WriteData(set, line, offset/4, data);
    }
    
    return;
}

void Instructor::ReplaceDatainCache(unsigned int pc, unsigned int set, unsigned int line, unsigned int offset ,unsigned int tag){
    unsigned int tempPC = pc & ~(offset);
    
    _cache.InsertTag(set, tag, line);
    for(int i = 0; i < 16; i++, tempPC+=4)
        _cache.InsertData(set, line, i, Instructor::_memory[tempPC/4]);
    
}



