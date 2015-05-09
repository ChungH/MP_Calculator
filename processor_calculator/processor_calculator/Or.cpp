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
    
    return false;
}

void Nor::MemoryAccess(){
    
}
void Nor::WriteBack(){
    
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Nor \nR[%d] = ~(R[%d] | R[%d]) => R[%d] = %8x\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);

}


//Or class

Or::Or(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : R_Instruction(rs,rt,rd,0,0,rsData,rtData){
    
}

bool Or::Execution(){
    _rdData = _rsData|_rtData;
    
  
    return false;
}
void Or::MemoryAccess(){
    
}
void Or::WriteBack(){
    Instructor::SetDataToRegister(_rd, _rdData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Or \nR[%d] = R[%d] | R[%d] => R[%d] = %8x\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
}
//OrImmediate class
OrImmediate::OrImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm, unsigned int rsData) : I_Instruction(rs,rt,zeroExtimm,rsData,-1){
    
}

bool OrImmediate::Execution(){
    
    _rtData = _rsData|_immediate;
    
  
    return false;
}

void OrImmediate::MemoryAccess(){
    
}
void OrImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : OrImmediate \nR[%d] = R[%d] | %d => R[%d] = %8x\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
}