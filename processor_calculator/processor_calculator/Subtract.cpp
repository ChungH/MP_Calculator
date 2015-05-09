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
Subtract::Subtract(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Subtract::Execution(){
    _rdData = _rsData - _rtData;

    return false;
}
void Subtract::MemoryAccess(){
    
}
void Subtract::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Subtract \nR[%d] = R[%d] - R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,_rdData);
    Instructor::AppendLog(logBuf);
    
}
//SubtractUnsigned class
SubtractUnsigned::SubtractUnsigned(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool SubtractUnsigned::Execution(){
    _rdData = _rsData - _rtData;
    
    return false;
}
void SubtractUnsigned::MemoryAccess(){
    
}
void SubtractUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : SubtractUnsigned \nR[%d] = R[%d] - R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,_rdData);
    Instructor::AppendLog(logBuf);
    
}
