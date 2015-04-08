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

Nor::Nor(unsigned int rs, unsigned int rt, unsigned int rd):R_Instruction(rs,rt,rd,0,0){
    
}

bool Nor::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    unsigned int resultData = ~(rsData|rtData);
    
    Instructor::SetDataToRegister(_rd, resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Nor \nR[%d] = ~(R[%d] | R[%d]) => R[%d] = %8x\n\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);

    
    return false;
}

//Or class

Or::Or(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool Or::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    unsigned int resultData = rsData|rtData;
    
    Instructor::SetDataToRegister(_rd, resultData);
    char logBuf[100];
    sprintf(logBuf, "Instruction : Or \nR[%d] = R[%d] | R[%d] => R[%d] = %8x\n\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}

//OrImmediate class
OrImmediate::OrImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm) : I_Instruction(rs,rt,zeroExtimm){
    
}

bool OrImmediate::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    
    unsigned int resultData = rsData|_immediate;
    
    Instructor::SetDataToRegister(_rt, resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : OrImmediate \nR[%d] = R[%d] | %d => R[%d] = %8x\n\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    return false;
}

