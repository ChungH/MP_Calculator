//
//  Move.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Move.h"
#include "Instructor.h"

//추가 구현 필요

//MoveFromHi class
MoveFromHi::MoveFromHi(unsigned int rd) : R_Instruction(0,0,rd,0,0){
    
}

bool MoveFromHi::Excution(){
    Instructor::SetDataToRegister(_rd, Instructor::_hi);
    return false;
}

//MoveFromLo class
MoveFromLo::MoveFromLo(unsigned int rd) : R_Instruction(0,0,rd,0,0){
    
}

bool MoveFromLo::Excution(){
    Instructor::SetDataToRegister(_rd, Instructor::_lo);
    return false;
}

//MoveToHi class
MoveToHi::MoveToHi(unsigned int rs) :R_Instruction(rs,0,0,0,0){
    
}

bool MoveToHi::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    Instructor::_hi = rsData;
    return false;
}


MoveToLo::MoveToLo(unsigned int rs) : R_Instruction(rs,0,0,0,0){
    
}


bool MoveToLo::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    Instructor::_lo = rsData;
    return false;
}



