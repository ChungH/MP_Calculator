//
//  main.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include <iostream>
#include "Instructor.h"
#include "Operate.h"
#include "FileIO.h"
#include "Queue.h"



int main(int argc, const char * argv[]) {

    FileIO*     fileManager = new FileIO;
    Instructor* instructor = new Instructor;
    Queue* instQueue;
    int reg_var[10];
    instQueue = fileManager->ReadInstruction();
    
    while(!instQueue->isEmpty()){
    instructor->ExcuteInstruction((char*)instQueue->Dequeue(instQueue),
                                  reg_var,fileManager);
    }
//    std::cout << reg_var[0] << std::endl;
    return 0;
}
