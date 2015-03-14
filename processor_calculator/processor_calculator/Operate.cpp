//
//  Operate.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Operate.h"

int Operate::Sum(int operand1, int operand2){
    return operand1+operand2;
}
int Operate::Sub(int operand1, int operand2){
    return operand1-operand2;
}
int Operate::Product(int operand1, int operand2){
    return operand1*operand2;
}
int Operate::Divide(int operand1, int operand2){
    return operand1/operand2;
}
int Operate::Modulus(int operand1, int operand2){
    return operand1%operand2;
}
