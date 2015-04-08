//
//  SetLessThan.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "SetLessThan.h"
#include "Instructor.h"

//SetLessThan class

SetLessThan::SetLessThan(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool SetLessThan::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, (rsData < rtData)? 1 : 0);

    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThan \nR[%d] = (R[%d]<R[%d])? 1:0 => R[%d] = %d\n\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);

    return false;
}

//SetLessThanUnsigned class
SetLessThanUnsigned::SetLessThanUnsigned(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool SetLessThanUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, (rsData < rtData)? 1 : 0);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThanUnsigned \nR[%d] = (R[%d]<R[%d])? 1:0 => R[%d] = %d\n\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    
    return false;
}


//SetLessThanImmediate class
SetLessThanImmediate::SetLessThanImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs,rt,signExtimm){
    
}

bool SetLessThanImmediate::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    Instructor::SetDataToRegister(_rt, (rsData < _immediate)? 1 : 0);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThanImmediate \nR[%d] = (R[%d]<%d)? 1:0 => R[%d] = %d\n\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    return false;
}

//SetLessThanImmediateUnsigned class
SetLessThanImmediateUnsigned::SetLessThanImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs,rt,signExtimm){
    
}

bool SetLessThanImmediateUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    Instructor::SetDataToRegister(_rt, (rsData < _immediate)? 1 : 0);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThanImmediateUnsigned \nR[%d] = (R[%d]<%d)? 1:0 => R[%d] = %d\n\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    return false;
}
