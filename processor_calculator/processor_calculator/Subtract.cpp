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
    Instructor::AppendLog("SUB,");
    return false;
}
void Subtract::MemoryAccess(){
    Instructor::AppendLog("SUB,");
}
void Subtract::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("SUB,");
}
//SubtractUnsigned class
SubtractUnsigned::SubtractUnsigned(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool SubtractUnsigned::Execution(){
    _rdData = _rsData - _rtData;
    
    Instructor::AppendLog("SUBU,");
    return false;
}
void SubtractUnsigned::MemoryAccess(){
    Instructor::AppendLog("SUBU,");
}
void SubtractUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("SUBU,");
}
