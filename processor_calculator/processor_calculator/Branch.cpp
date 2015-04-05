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


bool BranchOnEqual::Excution(){
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    unsigned int op2 = Instructor::GetDataFromRegister(_rt);
    if(op1 == op2){
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        return true;
    }
    return false;
}


//BranchOnNotEqual class

BranchOnNotEqual::BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr) : I_Instruction(rs, rt, branchAddr){
    
}

bool BranchOnNotEqual::Excution(){
    
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    unsigned int op2 = Instructor::GetDataFromRegister(_rt);
    if(op1 != op2){
        Instructor::_pc = Instructor::_pc + 4 + _immediate;
        return true;
    }
    return false;
}