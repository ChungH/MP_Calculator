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

SetLessThan::SetLessThan(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool SetLessThan::Execution(){
    
    _rdData = (_rsData < _rtData)? 1 : 0;

    return false;
}

void SetLessThan::MemoryAccess(){
    
}

void SetLessThan::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThan \nR[%d] = (R[%d]<R[%d])? 1:0 => R[%d] = %d\n\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);

}


//SetLessThanUnsigned class
SetLessThanUnsigned::SetLessThanUnsigned(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool SetLessThanUnsigned::Execution(){
    _rdData = (_rsData < _rtData)? 1 : 0;
 
    return false;
}

void SetLessThanUnsigned::MemoryAccess(){
    
}

void SetLessThanUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThanUnsigned \nR[%d] = (R[%d]<R[%d])? 1:0 => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
}


//SetLessThanImmediate class
SetLessThanImmediate::SetLessThanImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
    
}

bool SetLessThanImmediate::Execution(){
    _rtData = (_rsData < _immediate)? 1 : 0;
  
    return false;
}

void SetLessThanImmediate::MemoryAccess(){
    
}
void SetLessThanImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : SetLessThanImmediate \nR[%d] = (R[%d]<%d)? 1:0 => R[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
}


//SetLessThanImmediateUnsigned class
SetLessThanImmediateUnsigned::SetLessThanImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
    
}

bool SetLessThanImmediateUnsigned::Execution(){
    _rtData = (_rsData < _immediate)? 1 : 0;

    return false;
}

void SetLessThanImmediateUnsigned::MemoryAccess(){
    
}

void SetLessThanImmediateUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SetLessThanImmediateUnsigned \nR[%d] = (R[%d]<%d)? 1:0 => R[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
}
