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
    
    Instructor::AppendLog("DIV,");
    return false;
}

void Divide::MemoryAccess(){
    Instructor::AppendLog("DIV,");
}
void Divide::WriteBack(){
    Instructor::_lo = _lo;
    Instructor::_hi = _hi;
    
    Instructor::AppendLog("DIV,");
}


//DivideUnsigned class
DivideUnsigned::DivideUnsigned(unsigned int rs, unsigned int rt,unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool DivideUnsigned::Execution(){
    _lo = _rsData/_rtData;
    _hi = _rsData%_rtData;
    
   Instructor::AppendLog("DIVU,");
    
    return false;
}

void DivideUnsigned::MemoryAccess(){
    Instructor::AppendLog("DIVU,");
}
void DivideUnsigned::WriteBack(){
    Instructor::_lo = _lo;
    Instructor::_hi = _hi;
    
    Instructor::AppendLog("DIVU,");
    
}
