//
//  Multy.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Multiply.h"
#include "Instructor.h"

//추가 구현 필요

//Multiply class
Multiply::Multiply(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool Multiply::Excution(){
    return false;
}


//MultiplyUnsigned class
MultiplyUnsigned::MultiplyUnsigned(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool MultiplyUnsigned::Excution(){
    return false;
}


//Multiply32Bit class
Multiply32Bit::Multiply32Bit(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool Multiply32Bit::Excution(){
    
    return false;
}