//
//  Branch.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Branch.h"
#include "Instructor.h"

//BranchOnEqual class

BranchOnEqual::BranchOnEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr) :I_Instruction(rs, rt, branchAddr){

}


bool BranchOnEqual::Execution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    if(rsData == rtData){
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,rsData,_rt,rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        return true;
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,rsData,_rt,rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    return false;
}


//BranchOnNotEqual class

BranchOnNotEqual::BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr) : I_Instruction(rs, rt, branchAddr){
    
}

bool BranchOnNotEqual::Execution(){
    
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    if(rsData != rtData){
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,rsData,_rt,rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        
        return true;
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,rsData,_rt,rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    return false;
}

