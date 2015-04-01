//
//  Store.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class StoreByte : public I_Instruction{
public:
    StoreByte(unsigned int rs, unsigned int rt, unsigned int immediate);
public:
    virtual bool Excution();
};


class StoreConditional : public I_Instruction {
public:
    StoreConditional(unsigned int rs, unsigned int rt, unsigned int immediate);
public:
    virtual bool Excution();
};


class StoreHalfword : public I_Instruction {
public:
    StoreHalfword(unsigned int rs, unsigned int rt, unsigned int immediate);
public:
    virtual bool Excution();
};

class StoreWord : public I_Instruction {
public:
    StoreWord(unsigned int rs, unsigned int rt, unsigned int immediate);
public:
    virtual bool Excution();
};
