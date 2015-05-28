//
//  Or.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Or.h"
#include "Instructor.h"

//Nor class

Nor::Nor(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData):R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Nor::Execution(){
    _rdData = ~(_rsData|_rtData);
    Instructor::AppendLog("NOR,");
    return false;
}

void Nor::MemoryAccess(){
    Instructor::AppendLog("NOR,");
}
void Nor::WriteBack(){
    
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("NOR,");
}


//Or class

Or::Or(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Or::Execution(){
    _rdData = _rsData|_rtData;
    
    Instructor::AppendLog("OR,");
    return false;
}
void Or::MemoryAccess(){
    Instructor::AppendLog("OR,");
}
void Or::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("OR,");
}
//OrImmediate class
OrImmediate::OrImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm, unsigned int rsData) : I_Instruction(rs,rt,zeroExtimm,rsData,-1){
    
}

bool OrImmediate::Execution(){
    
    _rtData = _rsData|_immediate;
    
    Instructor::AppendLog("ORI,");
    return false;
}

void OrImmediate::MemoryAccess(){
    Instructor::AppendLog("ORI,");
}
void OrImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("ORI,");
}