//
//  Divide.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Divide.h"
#include "Instructor.h"

//Divide class
Divide::Divide(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool Divide::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    int rtData = Instructor::GetDataFromRegister(_rt);
    Instructor::_lo = rsData/rtData;
    Instructor::_hi = rsData%rtData;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Divide \nLo = R[%d]/R[%d] => Lo = %5d/%5d\nHi = R[%d]/R[%d] => Lo= %5d/%5d\n==================================\n",_rs,_rt,rsData,rtData,_rs,_rt,rsData,rtData);
    Instructor::AppendLog(logBuf);
    
    return false;
}

//DivideUnsigned class
DivideUnsigned::DivideUnsigned(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool DivideUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    Instructor::_lo = rsData/rtData;
    Instructor::_hi = rsData%rtData;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Divide \nLo = R[%d]/R[%d] => Lo = %5d/%5d\nHi = R[%d]/R[%d] => Lo= %5d/%5d\n==================================\n",_rs,_rt,rsData,rtData,_rs,_rt,rsData,rtData);
    Instructor::AppendLog(logBuf);
    
    return false;
}