//
//  Add.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Add.h"
#include "Instructor.h"


//Add class
Add::Add(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Add::Execution(){
    _rdData = _rsData + _rtData;
    
    Instructor::AppendLog("Add,");
 
    return false;
}
void Add::MemoryAccess(){
    Instructor::AppendLog("Add,");
}
void Add::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("Add,");
    
}

//AddUnsigned class

AddUnsigned::AddUnsigned(unsigned int rs, unsigned int rt,unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool AddUnsigned::Execution(){
    
    _rdData = _rsData + _rtData;
    Instructor::AppendLog("ADDU,");
    return false;
}

void AddUnsigned::MemoryAccess(){
    Instructor::AppendLog("ADDU,");
}
void AddUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    Instructor::AppendLog("ADDU,");
}


//AddImmediate class

AddImmediate::AddImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData): I_Instruction(rs, rt, signExtimm, rsData, -1){

}

bool AddImmediate::Execution(){

    _rtData = _rsData +  _immediate;
    Instructor::AppendLog("ADDI,");
    return false;
}

void AddImmediate::MemoryAccess(){
    Instructor::AppendLog("ADDI,");
}
void AddImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("ADDI,");
}

//AddImmediateUnsigned class

AddImmediateUnsigned::AddImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData) : I_Instruction(rs, rt,signExtimm, rsData, -1){
    
}

bool AddImmediateUnsigned::Execution(){
    
    _rtData = _rsData +  _immediate;
    Instructor::AppendLog("ADDIU,");
    return false;
}

void AddImmediateUnsigned::MemoryAccess(){
    Instructor::AppendLog("ADDIU,");
}
void AddImmediateUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("ADDIU,");
    
}




