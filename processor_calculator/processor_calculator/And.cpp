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
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : And \nR[%d] = R[%d] & R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}
void And::MemoryAccess(){
    
}
void And::WriteBack(){
       Instructor::SetDataToRegister(_rd, _rdData);
}

//AndImmediate class
AndImmediate::AndImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm, unsigned int rsData): I_Instruction(rs, rt, zeroExtimm, rsData, -1){
    
}

bool AndImmediate::Execution(){

    _rtData = _rsData & _immediate;
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : AndImmediate \nR[%d] = R[%d] & %x => R[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    
    return false;
}

void AndImmediate::MemoryAccess(){
    
}
void AndImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
}

