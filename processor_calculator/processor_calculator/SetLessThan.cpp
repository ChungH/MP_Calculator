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
    Instructor::AppendLog("SLT,");
    return false;
}

void SetLessThan::MemoryAccess(){
    Instructor::AppendLog("SLT,");
}

void SetLessThan::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("SLT,");
}


//SetLessThanUnsigned class
SetLessThanUnsigned::SetLessThanUnsigned(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool SetLessThanUnsigned::Execution(){
    _rdData = (_rsData < _rtData)? 1 : 0;
    Instructor::AppendLog("SLTU,");
    return false;
}

void SetLessThanUnsigned::MemoryAccess(){
    Instructor::AppendLog("SLTU,");
}

void SetLessThanUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("SLTU,");
}


//SetLessThanImmediate class
SetLessThanImmediate::SetLessThanImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
    
}

bool SetLessThanImmediate::Execution(){
    _rtData = (_rsData < _immediate)? 1 : 0;
    Instructor::AppendLog("SLTI,");
    return false;
}

void SetLessThanImmediate::MemoryAccess(){
    Instructor::AppendLog("SLTI,");
}
void SetLessThanImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("SLTI,");
}


//SetLessThanImmediateUnsigned class
SetLessThanImmediateUnsigned::SetLessThanImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
    
}

bool SetLessThanImmediateUnsigned::Execution(){
    _rtData = (_rsData < _immediate)? 1 : 0;

    Instructor::AppendLog("SLTIU,");
    return false;
}

void SetLessThanImmediateUnsigned::MemoryAccess(){
    Instructor::AppendLog("SLTIU,");
}

void SetLessThanImmediateUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("SLTIU,");
    
}
