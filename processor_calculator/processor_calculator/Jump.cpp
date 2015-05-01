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
    
}

bool Jump::Execution(){
    Instructor::_pc = _address;
    char logBuf[100];
    sprintf(logBuf, "Instruction : Jump \nPC = JumpAddr => PC : %5d  \n==================================\n",_address);
    Instructor::AppendLog(logBuf);
    return true;
}


//JumpAndLink class
JumpAndLink::JumpAndLink(unsigned int jumpAddr) : J_Instruction(jumpAddr){
    
}

bool JumpAndLink::Execution(){
    Instructor::SetDataToRegister(31, Instructor::_pc + 8);
    Instructor::_pc = _address;
    char logBuf[200];
    sprintf(logBuf, "Instruction : JumpAndLink \nR[31] = PC+4 -> R[31] = %5d\nPC = JumpAddr => PC = %5d\n==================================\n",Instructor::_pc - 4, _address);
    Instructor::AppendLog(logBuf);
    return true;
}



//JumpRegister class

JumpRegister::JumpRegister(unsigned int rs) : R_Instruction(rs,0,0,0,0){
    
}

bool JumpRegister::Execution(){
    Instructor::_pc = Instructor::GetDataFromRegister(_rs);
    char logBuf[100];
    sprintf(logBuf, "Instruction : JumpRegister \nPC = R[%d] => PC : %5d  \n==================================\n",_rs,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    return true;
}

