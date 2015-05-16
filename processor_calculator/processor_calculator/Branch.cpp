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

BranchOnEqual::BranchOnEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData, unsigned int prevPC) :I_Instruction(rs, rt, branchAddr,rsData,rtData),_prevPC(prevPC){
    _writeChk = false;
}

bool BranchOnEqual::Execution(){

    //Instructor::_pc = Instructor::_pc + 4 + _immediate;
    
    if(_rsData == _rtData){
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        
        if(Instructor::_lastBranch <= 1){
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            return false;
        }
        else{
            Instructor::_pc = _prevPC + 4 + _immediate;
//            Instructor::_pc = Instructor::_pc + _immediate;
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            return true;
        }
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    if(Instructor::_lastBranch <= 1){
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        Instructor::_pc = _prevPC + 4;
        return true;
    }
    else{
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        return false;
    }
}
void BranchOnEqual::MemoryAccess(){
    
}
void BranchOnEqual::WriteBack(){
    
}







//BranchOnNotEqual class

BranchOnNotEqual::BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData, unsigned int prevPC) : I_Instruction(rs, rt, branchAddr, rsData, rtData), _prevPC(prevPC){
    _writeChk = false;
    
}

bool BranchOnNotEqual::Execution(){
    
    if(_rsData != _rtData){
        
        char logBuf[200];
        sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
        Instructor::AppendLog(logBuf);
        
        if(Instructor::_lastBranch <= 1){
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            return false;
        }
        else{
            Instructor::_pc = _prevPC + 4 + _immediate;
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            return true;
        }
    }
    
    char logBuf[200];
    sprintf(logBuf, "Instruction : BranchOnNotEqual \nR[%d] : %5d R[%d] : %5d\nbranchAddr : %d\nPC: %5d\n==================================\n",_rs,_rsData,_rt,_rtData,_immediate,Instructor::_pc);
    Instructor::AppendLog(logBuf);
    
    if(Instructor::_lastBranch <= 1){
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        Instructor::_pc = _prevPC + 4;
        return true;
    }
    else{
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        return false;
    }
}

void BranchOnNotEqual::MemoryAccess(){
    
}
void BranchOnNotEqual::WriteBack(){
    
}