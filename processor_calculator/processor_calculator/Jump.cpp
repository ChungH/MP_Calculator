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
    Instructor::AppendLog("J,");
    return false;
}

void Jump::MemoryAccess(){
    Instructor::AppendLog("J,");
}
void Jump::WriteBack(){
    Instructor::AppendLog("J,");
}


//JumpAndLink class
JumpAndLink::JumpAndLink(unsigned int jumpAddr,unsigned int pc) : J_Instruction(jumpAddr){
    _rd = 31;
    _pc = pc;
    _writeChk = true;
}

bool JumpAndLink::Execution(){
    Instructor::AppendLog("JAL,");
    _rdData = _pc + 8;
    return false;
}

void JumpAndLink::MemoryAccess(){
    Instructor::AppendLog("JAL,");
}
void JumpAndLink::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("JAL,");
}

//JumpRegister class

JumpRegister::JumpRegister(unsigned int rs, unsigned int rsData) : R_Instruction(rs,0,0,0,0,rsData,-1){
    _writeChk = false;
}

bool JumpRegister::Execution(){
    Instructor::AppendLog("JR,");
    return false;
}

void JumpRegister::MemoryAccess(){
    Instructor::AppendLog("JR,");
}
void JumpRegister::WriteBack(){
    Instructor::AppendLog("JR,");
}
