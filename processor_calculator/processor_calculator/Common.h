//
//  Common.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instructor.h"

#define GET_SET_FUNCT(TYPE, FUNC_NAME, VAR) \
    TYPE get##FUNC_NAME(void) { return VAR; } \
    void set##FUNC_NAME(TYPE par_var) { VAR = par_var; }

