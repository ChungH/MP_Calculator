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
 
    return false;
}
void Add::MemoryAccess(){

}
void Add::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Add \nR[%d] = R[%d] + R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
}

//AddUnsigned class

AddUnsigned::AddUnsigned(unsigned int rs, unsigned int rt,unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool AddUnsigned::Execution(){
    
    _rdData = _rsData + _rtData;
    
    return false;
}

void AddUnsigned::MemoryAccess(){
    
}
void AddUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : AddUnsigned \nR[%d] = R[%d] + R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
}


//AddImmediate class

AddImmediate::AddImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData): I_Instruction(rs, rt, signExtimm, rsData, -1){

}

bool AddImmediate::Execution(){

    _rtData = _rsData +  _immediate;

    return false;
}

void AddImmediate::MemoryAccess(){
    
}
void AddImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : AddImmediate \nR[%d] = R[%d] + %d =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
}

//AddImmediateUnsigned class

AddImmediateUnsigned::AddImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData) : I_Instruction(rs, rt,signExtimm, rsData, -1){
    
}

bool AddImmediateUnsigned::Execution(){
    
    _rtData = _rsData +  _immediate;
 
    return false;
}

void AddImmediateUnsigned::MemoryAccess(){
    
}
void AddImmediateUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : AddImmediateUnsigned \nR[%d] = R[%d] + %d =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate, _rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
}




