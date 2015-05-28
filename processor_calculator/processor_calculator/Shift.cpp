//
//  Shift.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Shift.h"
#include "Instructor.h"

//ShiftLeftLogical class
ShiftLeftLogical::ShiftLeftLogical(unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int rtData) : R_Instruction(0,rt,rd,shamt,0,-1,rtData){
    
}

bool ShiftLeftLogical::Execution(){
    _rdData = _rtData << _shamt;

    Instructor::AppendLog("SLL,");
    return false;
}
void ShiftLeftLogical::MemoryAccess(){
    Instructor::AppendLog("SLL,");
}
void ShiftLeftLogical::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);

   Instructor::AppendLog("SLL,");
}

//ShiftRightLogical class

ShiftRightLogical::ShiftRightLogical(unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int rtData) : R_Instruction(0,rt,rd,shamt,0,-1,rtData){
    
}

bool ShiftRightLogical::Execution(){
    _rdData = _rtData >> _shamt;
 
    Instructor::AppendLog("SRL,");
    return false;
}

void ShiftRightLogical::MemoryAccess(){
    Instructor::AppendLog("SRL,");
}

void ShiftRightLogical::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("SRL,");
}


