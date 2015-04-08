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
ShiftLeftLogical::ShiftLeftLogical(unsigned int rt, unsigned int rd, unsigned int shamt) : R_Instruction(0,rt,rd,shamt,0){
    
}

bool ShiftLeftLogical::Excution(){
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned int resultData = rtData << _shamt;
    Instructor::SetDataToRegister(_rd, resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : ShiftLeftLogical \nR[%d] = R[%d] << %d => R[%d] = %d\n==================================\n",_rd,_rs,_shamt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}

//ShiftRightLogical class

ShiftRightLogical::ShiftRightLogical(unsigned int rt, unsigned int rd, unsigned int shamt) : R_Instruction(0,rt,rd,shamt,0){
    
}

bool ShiftRightLogical::Excution(){
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned int resultData = rtData >> _shamt;
    Instructor::SetDataToRegister(_rd, resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : ShiftRightLogical \nR[%d] = R[%d] >> %d => R[%d] = %d\n==================================\n",_rd,_rs,_shamt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}