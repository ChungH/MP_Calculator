//
//  Shift.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Shift.h"
#include "Instructor.h"

//ShiftLeftLogical class
ShiftLeftLogical::ShiftLeftLogical(unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int rtData) : R_Instruction(0,rt,rd,shamt,0,-1,rtData){
    
}

bool ShiftLeftLogical::Execution(){

    _rdData = _rtData << _shamt;

    return false;
}
void ShiftLeftLogical::MemoryAccess(){
    
}
void ShiftLeftLogical::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);

    char logBuf[100];
    sprintf(logBuf, "Instruction : ShiftLeftLogical \nR[%d] = R[%d] << %d => R[%d] = %d\n==================================\n",_rd,_rs,_shamt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
}

//ShiftRightLogical class

ShiftRightLogical::ShiftRightLogical(unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int rtData) : R_Instruction(0,rt,rd,shamt,0,-1,rtData){
    
}

bool ShiftRightLogical::Execution(){

    _rdData = _rtData >> _shamt;
 
    return false;
}

void ShiftRightLogical::MemoryAccess(){
    
}

void ShiftRightLogical::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : ShiftRightLogical \nR[%d] = R[%d] >> %d => R[%d] = %d\n==================================\n",_rd,_rs,_shamt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
}


