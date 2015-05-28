//
//  And.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "And.h"
#include "Instructor.h"

//And class
And::And(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs, rt, rd, 0, 0, rsData, rtData){
}

bool And::Execution(){

    _rdData = _rsData & _rtData;
    Instructor::AppendLog("AND,");
    return false;
}
void And::MemoryAccess(){
    Instructor::AppendLog("AND,");
}
void And::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("AND,");
}

//AndImmediate class
AndImmediate::AndImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm, unsigned int rsData): I_Instruction(rs, rt, zeroExtimm, rsData, -1){
    
}

bool AndImmediate::Execution(){

    _rtData = _rsData & _immediate;
    Instructor::AppendLog("ANDI,");
    return false;
}

void AndImmediate::MemoryAccess(){
    Instructor::AppendLog("ANDI,");
}
void AndImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("ANDI,");
    
}

