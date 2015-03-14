//
//  Operate.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#ifndef __processor_calculator__Operate__
#define __processor_calculator__Operate__

#include <iostream>

class Operate {

public:
    Operate();
    ~Operate();
public:
    static int Sum(int operand1, int operand2);
    static int Sub(int operand1, int operand2);
    static int Mul(int operand1, int operand2);
    static int Div(int operand1, int operand2);
    static int Mod(int operand1, int operand2);
    static void Move(int* reg, int value);                  //overide
    static void Move(int* reg1, int* reg2);                 //overide
    
};


#endif /* defined(__processor_calculator__Operate__) */
