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
    Instructor::AppendLog("BEQ,");
    
    if(_rsData == _rtData){
        if(Instructor::_lastBranch <= 1){
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
                Instructor::_predictionHit++;
            return false;
        }
        else{
            Instructor::_pc = _prevPC + 4 + _immediate;
//            Instructor::_pc = Instructor::_pc + _immediate;
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
                Instructor::_predictionMiss++;
            return true;
        }
    }
    
    if(Instructor::_lastBranch <= 1){
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        Instructor::_pc = _prevPC + 4;
        Instructor::_predictionMiss++;
        return true;
    }
    else{
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
            Instructor::_predictionHit++;
        return false;
    }
}
void BranchOnEqual::MemoryAccess(){
    Instructor::AppendLog("BEQ,");
}
void BranchOnEqual::WriteBack(){
    Instructor::AppendLog("BEQ,");
}







//BranchOnNotEqual class

BranchOnNotEqual::BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData, unsigned int prevPC) : I_Instruction(rs, rt, branchAddr, rsData, rtData), _prevPC(prevPC){
    _writeChk = false;
    
}

bool BranchOnNotEqual::Execution(){
    Instructor::AppendLog("BNE,");
    if(_rsData != _rtData){
        if(Instructor::_lastBranch <= 1){
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            Instructor::_predictionHit++;
            return false;
        }
        else{
            Instructor::_pc = _prevPC + 4 + _immediate;
            Instructor::_lastBranch--;
            if(Instructor::_lastBranch == -1)
                Instructor::_lastBranch = 0;
            Instructor::_predictionMiss++;
            return true;
        }
    }
    if(Instructor::_lastBranch <= 1){
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
        Instructor::_pc = _prevPC + 4;
        Instructor::_predictionMiss++;
        return true;
    }
    else{
        Instructor::_lastBranch++;
        if(Instructor::_lastBranch == 4)
            Instructor::_lastBranch = 3;
            Instructor::_predictionHit++;
        return false;
    }
}

void BranchOnNotEqual::MemoryAccess(){
    Instructor::AppendLog("BNE,");
}
void BranchOnNotEqual::WriteBack(){
    Instructor::AppendLog("BNE,");
}