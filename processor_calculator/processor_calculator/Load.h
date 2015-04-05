//
//  Load.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class LoadByteUnsigned : public I_Instruction {
public:
    LoadByteUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Excution();
};

class LoadHalfwordUnsigned : public I_Instruction {
public:
    LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Excution();
};

class LoadLinked : public I_Instruction {
public:
    LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Excution();
};

class LoadUpperImmediate : public I_Instruction {
public:
    LoadUpperImmediate(unsigned int rt, unsigned int immediate);
public:
    virtual bool Excution();
};


class LoadWord : public I_Instruction {
public:
    LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Excution();
};
