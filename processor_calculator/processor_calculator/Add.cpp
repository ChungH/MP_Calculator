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
Add::Add(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs, rt, rd, 0,0){
}

bool Add::Excution(){
    int rsData = Instructor::GetDataFromRegister(_rs);
    int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, rsData + rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : Add \nR[%d] = R[%d] + R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    return false;
}


//AddUnsigned class

AddUnsigned::AddUnsigned(unsigned int rs, unsigned int rt,unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool AddUnsigned::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, rsData + rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : AddUnsigned \nR[%d] = R[%d] + R[%d] => R[%d] = %d\n==================================\n",_rd,_rs,_rt,_rd,Instructor::GetDataFromRegister(_rd));
    Instructor::AppendLog(logBuf);
    
    
    return false;
}



//AddImmediate class

AddImmediate::AddImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm): I_Instruction(rs, rt, signExtimm){

}

bool AddImmediate::Excution(){
    
    int rsData = Instructor::GetDataFromRegister(_rs);
    
    Instructor::SetDataToRegister(_rt, rsData +  _immediate);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : AddImmediate \nR[%d] = R[%d] + %d =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    return false;
}

//AddImmediateUnsigned class

AddImmediateUnsigned::AddImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt,signExtimm){
    
}

bool AddImmediateUnsigned::Excution(){
    
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    
    Instructor::SetDataToRegister(_rt, rsData +  _immediate);
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : AddImmediateUnsigned \nR[%d] = R[%d] + %d =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate, _rt,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    
    return false;
}






