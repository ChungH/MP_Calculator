//
//  main.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#include <iostream>
#include <string.h>
#include "Instructor.h"


std::array<unsigned int, MAX_MEMORY> Instructor::_memory;
std::array<unsigned int, 32>   Instructor::_register;
unsigned int                   Instructor::_pc;
unsigned int                   Instructor::_hi;
unsigned int                   Instructor::_lo;
std::string                    Instructor::_logBuffer;
int                            Instructor::_lastBranch;

//bool isLittleEndian()
//{
//    union{
//        int a;
//        char b[4];
//    }Test;
//    
//    Test.a = 1;
//    printf("%x %x %x %x",Test.b[0], Test.b[1], Test.b[2], Test.b[3]);
//    return Test.b;
//}

int main(int argc, const char * argv[]) {
    
    const char* filePath = argv[1];

    Instructor::AppendLog("Opened File : ");
//    Instructor::AppendLog(filePath);
    Instructor::AppendLog("\n\n");
    
    Instructor* instructor = new Instructor(filePath);
    Instructor::_memory.fill(0);
    Instructor::_register.fill(0);
    Instructor::_pc = 0;
    instructor->ExecuteInstruction();
    
    Instructor::PrintLog("./outputLog.txt");
    delete instructor;

    return 0;
}