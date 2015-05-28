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
MoveFromHi::MoveFromHi(unsigned int rd) : R_Instruction(0,0,rd,0,0,0,0){
    
}

bool MoveFromHi::Execution(){
    Instructor::AppendLog("MFH,");
    return false;
}

void MoveFromHi::MemoryAccess(){
    Instructor::AppendLog("MFH,");
}
void MoveFromHi::WriteBack(){
    Instructor::SetDataToRegister(_rd, Instructor::_hi);
    
    Instructor::AppendLog("MFH,");
}

//MoveFromLo class
MoveFromLo::MoveFromLo(unsigned int rd) : R_Instruction(0,0,rd,0,0,0,0){
    
}

bool MoveFromLo::Execution(){

    Instructor::AppendLog("MFL,");
    return false;
}
void MoveFromLo::MemoryAccess(){
    Instructor::AppendLog("MFL,");
}
void MoveFromLo::WriteBack(){
    Instructor::SetDataToRegister(_rd, Instructor::_lo);
    
    Instructor::AppendLog("MFL,");
}

//MoveToHi class
MoveToHi::MoveToHi(unsigned int rs, unsigned int rsData) :R_Instruction(rs,0,0,0,0,rsData,0){
    
}

bool MoveToHi::Execution(){
    Instructor::AppendLog("MTH,");
    return false;
}

void MoveToHi::MemoryAccess(){
    Instructor::AppendLog("MTH,");
}
void MoveToHi::WriteBack(){
    Instructor::_hi = _rsData;
    
    Instructor::AppendLog("MTH,");
}

//MoveToLo class
MoveToLo::MoveToLo(unsigned int rs, unsigned int rsData) : R_Instruction(rs,0,0,0,0,rsData,0){
    
}


bool MoveToLo::Execution(){
    Instructor::AppendLog("MTL,");
    return false;
}

void MoveToLo::MemoryAccess(){
    Instructor::AppendLog("MTL,");
}
void MoveToLo::WriteBack(){
    Instructor::_lo = _rsData;
    
    Instructor::AppendLog("MTL,");
}

