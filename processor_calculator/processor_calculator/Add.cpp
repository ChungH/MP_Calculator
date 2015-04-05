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
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    unsigned int op2 = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, op1 + op2);
    return false;
}


//AddUnsigned class

AddUnsigned::AddUnsigned(unsigned int rs, unsigned int rt,unsigned int rd) : R_Instruction(rs,rt,rd,0,0){
    
}

bool AddUnsigned::Excution(){
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    unsigned int op2 = Instructor::GetDataFromRegister(_rt);
    
    Instructor::SetDataToRegister(_rd, op1 + op2);
    return false;
}



//AddImmediate class

AddImmediate::AddImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm): I_Instruction(rs, rt, signExtimm){

}

bool AddImmediate::Excution(){
    
    int op1 = Instructor::GetDataFromRegister(_rs);
    
    Instructor::SetDataToRegister(_rt, op1 +  _immediate);
    
    return false;
}

//AddImmediateUnsigned class

AddImmediateUnsigned::AddImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt,signExtimm){
    
}

bool AddImmediateUnsigned::Excution(){
    
    unsigned int op1 = Instructor::GetDataFromRegister(_rs);
    
    Instructor::SetDataToRegister(_rt, op1 +  _immediate);
    
    return false;
}






