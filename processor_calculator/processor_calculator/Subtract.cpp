//
//  Subtract.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Subtract.h"
#include "Instructor.h"

//Subtract class
Subtract::Subtract(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool Subtract::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rt, rsData - rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Subtract \nR[%d] = R[%d] - R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}

//SubtractUnsigned class
SubtractUnsigned::SubtractUnsigned(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool SubtractUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rt, rsData - rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SubtractUnsigned \nR[%d] = R[%d] - R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    
    return false;
}

