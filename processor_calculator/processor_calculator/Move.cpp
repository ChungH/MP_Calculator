//
//  Move.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Move.h"
#include "Instructor.h"

//추가 구현 필요

//MoveFromHi class
MoveFromHi::MoveFromHi(unsigned int rd) : R_Instruction(0,0,rd,0,0){
    
}

bool MoveFromHi::Excution(){
    
    return false;
}

//MoveFromLo class
MoveFromLo::MoveFromLo(unsigned int rd) : R_Instruction(0,0,rd,0,0){
    
}

bool MoveFromLo::Excution(){
    
    return false;
}

