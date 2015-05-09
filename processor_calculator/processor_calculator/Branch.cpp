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

BranchOnEqual::BranchOnEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData) :I_Instruction(rs, rt, branchAddr,rsData,rtData){

}

bool BranchOnEqual::Execution(){
    
    if(_rsData == _rtData){
        _branchChk = true;
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        return true;
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    return false;
}
void MemoryAccess(){
    
}
void WriteBack(){
    
}

//BranchOnNotEqual class

BranchOnNotEqual::BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData) : I_Instruction(rs, rt, branchAddr, rsData, rtData){
    
}

bool BranchOnNotEqual::Execution(){
    
    if(_rsData != _rtData){
        _branchChk = true;
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        
        return true;
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    return false;
}

