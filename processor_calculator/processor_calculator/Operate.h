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
    int Sum(int operand1, int operand2);
    int Sub(int operand1, int operand2);
    int Product(int operand1, int operand2);
    int Divide(int operand1, int operand2);
    int Modulus(int operand1, int operand2);
    
};


#endif /* defined(__processor_calculator__Operate__) */
