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

int main(int argc, const char * argv[]) {

    int reg_var[10];
    char s[] = "M R0 0x51";
    
    Instructor inst;
    inst.ExcuteInstruction(s, reg_var);
    std::cout << reg_var[0] << std::endl;
    
    char s2[] = "M R1 0x2012";
    inst.ExcuteInstruction(s2, reg_var);
    std::cout << reg_var[1] << std::endl;

    char s3[] = "M R2 R0";
    inst.ExcuteInstruction(s3, reg_var);
    std::cout << reg_var[2] << std::endl;
    return 0;
}
