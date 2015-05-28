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
    Instructor::AppendLog("MULT,");
    return false;
}

void Multiply::MemoryAccess(){
    Instructor::AppendLog("MULT,");
}
void Multiply::WriteBack(){
    Instructor::_hi = _resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = _resultData & 0x00000000ffffffff;
    
    Instructor::AppendLog("MULT,");
}

//MultiplyUnsigned class
MultiplyUnsigned::MultiplyUnsigned(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,0,0,0,rsData,rtData){
    
}

bool MultiplyUnsigned::Execution(){
    _resultData = _rsData * _rtData;

    Instructor::AppendLog("MULTU,");
    return false;
}

void MultiplyUnsigned::MemoryAccess(){
    Instructor::AppendLog("MULTU,");
    
}
void MultiplyUnsigned::WriteBack(){
    Instructor::_hi = _resultData & 0xffffffff00000000 >> 32;
    Instructor::_lo = _resultData & 0x00000000ffffffff;
    
    Instructor::AppendLog("MULTU,");
}



//Multiply32Bit class
Multiply32Bit::Multiply32Bit(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Multiply32Bit::Execution(){
    
    _rdData = _rsData * _rtData;
    Instructor::AppendLog("MULT32,");
    return false;
}

void Multiply32Bit::MemoryAccess(){
    Instructor::AppendLog("MULT32,");
}
void Multiply32Bit::WriteBack(){
    
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("MULT32,");
}



