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

bool Jump::Excution(){
    Instructor::_pc = _address;
    return true;
}


//JumpAndLink class
JumpAndLink::JumpAndLink(unsigned int jumpAddr) : J_Instruction(jumpAddr){
    
}

bool JumpAndLink::Excution(){
    Instructor::SetDataToRegister(31, Instructor::_pc + 8);
    Instructor::_pc = _address;
    return true;
}



//JumpRegister class

JumpRegister::JumpRegister(unsigned int rs) : R_Instruction(rs,0,0,0,0){
    
}

bool JumpRegister::Excution(){
    Instructor::_pc = Instructor::GetDataFromRegister(_rs);
    return true;
}

