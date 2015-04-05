//
//  Divide.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Divide.h"
#include "Instructor.h"

//추가 구현 필요

//Divide class
Divide::Divide(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool Divide::Excution(){
    
    return false;
}

//DivideUnsigned class
DivideUnsigned::DivideUnsigned(unsigned int rs, unsigned int rt) : R_Instruction(rs,rt,0,0,0){
    
}

bool DivideUnsigned::Excution(){
    
    return false;
}