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

    return false;
}

void MoveFromHi::MemoryAccess(){
    
}
void MoveFromHi::WriteBack(){
    Instructor::SetDataToRegister(_rd, Instructor::_hi);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MoveFromHi \nR[%d] = Hi => R[%d] = %5d\n==================================\n",_rd,_rd,Instructor::_hi);
    Instructor::AppendLog(logBuf);
}

//MoveFromLo class
MoveFromLo::MoveFromLo(unsigned int rd) : R_Instruction(0,0,rd,0,0,0,0){
    
}

bool MoveFromLo::Execution(){


    return false;
}
void MoveFromLo::MemoryAccess(){
    
}
void MoveFromLo::WriteBack(){
    Instructor::SetDataToRegister(_rd, Instructor::_lo);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MoveFromLo \nR[%d] = Lo => R[%d] = %5d\n==================================\n",_rd,_rd,Instructor::_lo);
    Instructor::AppendLog(logBuf);
}

//MoveToHi class
MoveToHi::MoveToHi(unsigned int rs, unsigned int rsData) :R_Instruction(rs,0,0,0,0,rsData,0){
    
}

bool MoveToHi::Execution(){

    return false;
}

void MoveToHi::MemoryAccess(){
    
}
void MoveToHi::WriteBack(){
    Instructor::_hi = _rsData;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MoveToHi \nHi = R[%d] => Hi = %5d\n==================================\n",_rs,Instructor::_hi);
    Instructor::AppendLog(logBuf);
    
}

//MoveToLo class
MoveToLo::MoveToLo(unsigned int rs, unsigned int rsData) : R_Instruction(rs,0,0,0,0,rsData,0){
    
}


bool MoveToLo::Execution(){

  
    return false;
}

void MoveToLo::MemoryAccess(){
    
}
void MoveToLo::WriteBack(){
    Instructor::_lo = _rsData;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MoveToLo \nHi = R[%d] => Lo = %5d\n==================================\n",_rs,Instructor::_lo);
    Instructor::AppendLog(logBuf);
    
    
}

