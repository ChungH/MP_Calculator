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
Multiply::Multiply(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool Multiply::Execution(){

    _resultData = _rsData * _rtData;

    return false;
}

void Multiply::MemoryAccess(){
    
}
void Multiply::WriteBack(){
    Instructor::_hi = _resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = _resultData & 0x00000000ffffffff;
    
    
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Multiply \n{Hi,Lo} = R[%d] * R[%d] => Hi = %5d Lo = %5d\n==================================\n",_rs,_rt,Instructor::_hi,Instructor::_lo);
    Instructor::AppendLog(logBuf);
    
    
}

//MultiplyUnsigned class
MultiplyUnsigned::MultiplyUnsigned(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool MultiplyUnsigned::Execution(){
    _resultData = _rsData * _rtData;

    
    return false;
}

void MultiplyUnsigned::MemoryAccess(){
    
}
void MultiplyUnsigned::WriteBack(){
    Instructor::_hi = _resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = _resultData & 0x00000000ffffffff;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : MultiplyUnsigned \n{Hi,Lo} = R[%d] * R[%d] => Hi = %5d Lo = %5d\n==================================\n",_rs,_rt,Instructor::_hi,Instructor::_lo);
    Instructor::AppendLog(logBuf);
}



//Multiply32Bit class
Multiply32Bit::Multiply32Bit(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Multiply32Bit::Execution(){
    
    _rdData = _rsData * _rtData;
    
    return false;
}

void Multiply32Bit::MemoryAccess(){
    
}
void Multiply32Bit::WriteBack(){
    
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Multiply32Bit \nR[%d] = R[%d] * R[%d] => R[%d] = %5d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    

}



