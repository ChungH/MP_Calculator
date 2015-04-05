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
And::And(unsigned int rs, unsigned int rt, unsigned int rd) : R_Instruction(rs, rt, rd, 0, 0){
}

bool And::Excution(){
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    unsigned int op2 = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, op1 & op2);
    
    return false;
}

//AndImmediate class
AndImmediate::AndImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm): I_Instruction(rs, rt, zeroExtimm){
    
}

bool AndImmediate::Excution(){
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    
    Instructor::SetDataToRegister(_rt, op1 & _immediate);
    
    return false;
}