//
//  main.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#include <iostream>
#include "Instructor.h"


std::array<unsigned int, 8192> Instructor::_memory;
std::array<unsigned int, 32>   Instructor::_register;


int main(int argc, const char * argv[]) {
    
    Instructor* instructor = new Instructor();
    Instructor::_memory.fill(0);
    Instructor::_register.fill(0);
    
//    instructor->ExcuteInstruction();

    delete instructor;

    return 0;
}
