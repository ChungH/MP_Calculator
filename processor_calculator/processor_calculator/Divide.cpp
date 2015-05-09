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
Divide::Divide(unsigned int rs, unsigned int rt,unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool Divide::Execution(){
    _lo = _rsData / _rtData;
    _hi = _rsData % _rtData;
    
 
    return false;
}

void Divide::MemoryAccess(){
    
}
void Divide::WriteBack(){
    Instructor::_lo = _lo;
    Instructor::_hi = _hi;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Divide \nLo = R[%d]/R[%d] => Lo = %5d/%5d\nHi = R[%d]/R[%d] => Lo= %5d/%5d\n==================================\n",_rs,_rt,_rsData,_rtData,_rs,_rt,_rsData,_rtData);
    Instructor::AppendLog(logBuf);
    
    
}


//DivideUnsigned class
DivideUnsigned::DivideUnsigned(unsigned int rs, unsigned int rt,unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool DivideUnsigned::Execution(){
    _lo = _rsData/_rtData;
    _hi = _rsData%_rtData;
    
   
    
    return false;
}

void DivideUnsigned::MemoryAccess(){
    
}
void DivideUnsigned::WriteBack(){
    Instructor::_lo = _lo;
    Instructor::_hi = _hi;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Divide \nLo = R[%d]/R[%d] => Lo = %5d/%5d\nHi = R[%d]/R[%d] => Lo= %5d/%5d\n==================================\n",_rs,_rt,_rsData,_rtData,_rs,_rt,_rsData,_rtData);
    Instructor::AppendLog(logBuf);
    
}
