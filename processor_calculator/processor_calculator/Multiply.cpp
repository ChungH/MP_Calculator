//
//  Multy.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Multiply.h"
#include "Instructor.h"

//추가 구현 필요

//Multiply class
Multiply::Multiply(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool Multiply::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    int rtData = Instructor::GetDataFromRegister(_rt);
    long long resultData = rsData * rtData;
    Instructor::_hi = resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = resultData & 0x00000000ffffffff;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Multiply \n{Hi,Lo} = R[%d] * R[%d] => Hi = %5d Lo = %5d\n==================================\n",_rs,_rt,Instructor::_hi,Instructor::_lo);
    Instructor::AppendLog(logBuf);
    
    return false;
}


//MultiplyUnsigned class
MultiplyUnsigned::MultiplyUnsigned(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool MultiplyUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned long long resultData = rsData * rtData;
    Instructor::_hi = resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = resultData & 0x00000000ffffffff;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MultiplyUnsigned \n{Hi,Lo} = R[%d] * R[%d] => Hi = %5d Lo = %5d\n==================================\n",_rs,_rt,Instructor::_hi,Instructor::_lo);
    Instructor::AppendLog(logBuf);
    
    return false;
}


//Multiply32Bit class
Multiply32Bit::Multiply32Bit(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool Multiply32Bit::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, rsData * rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Multiply32Bit \nR[%d] = R[%d] * R[%d] => R[%d] = %5d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    
    return false;
}