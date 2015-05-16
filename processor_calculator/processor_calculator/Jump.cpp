//
//  Jump.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Jump.h"
#include "Instructor.h"

//Jump class

Jump::Jump(unsigned int jumpAddr) : J_Instruction(jumpAddr){
    _writeChk = false;
}

bool Jump::Execution(){
    char logBuf[100];
    sprintf(logBuf, "Instruction : Jump \nPC = JumpAddr => PC : %5d  \n==================================\n",_address);
    Instructor::AppendLog(logBuf);
    return false;
}

void Jump::MemoryAccess(){
    
}
void Jump::WriteBack(){
}


//JumpAndLink class
JumpAndLink::JumpAndLink(unsigned int jumpAddr,unsigned int pc) : J_Instruction(jumpAddr){
    _rd = 31;
    _pc = pc;
    _writeChk = true;
}

bool JumpAndLink::Execution(){
    char logBuf[200];
    sprintf(logBuf, "Instruction : JumpAndLink \nR[31] = PC+4 -> R[31] = %5d\nPC = JumpAddr => PC = %5d\n==================================\n",Instructor::_pc - 4, _address);
    Instructor::AppendLog(logBuf);
    return false;
}

void JumpAndLink::MemoryAccess(){
    
}
void JumpAndLink::WriteBack(){
    Instructor::SetDataToRegister(_rd, _pc + 8);
}

//JumpRegister class

JumpRegister::JumpRegister(unsigned int rs, unsigned int rsData) : R_Instruction(rs,0,0,0,0,rsData,-1){
    _writeChk = false;
}

bool JumpRegister::Execution(){
    char logBuf[100];
    sprintf(logBuf, "Instruction : JumpRegister \nPC = R[%d] => PC : %5d  \n==================================\n",_rs,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    return false;
}

void JumpRegister::MemoryAccess(){
    
}
void JumpRegister::WriteBack(){

}
