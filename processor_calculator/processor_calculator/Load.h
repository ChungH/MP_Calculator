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
    unsigned int _memoryData;
    unsigned int _maskedData;
public:
    LoadByteUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class LoadHalfwordUnsigned : public I_Instruction {
    
public:
    unsigned int _memoryData;
    unsigned int _maskedData;
public:
    LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class LoadLinked : public I_Instruction {
public:
    unsigned int _memoryData;
    unsigned int _maskedData;
public:
    LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class LoadUpperImmediate : public I_Instruction {
public:
    unsigned int _maskedData;
public:
    LoadUpperImmediate(unsigned int rt, unsigned int immediate);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class LoadWord : public I_Instruction {
public:
    unsigned int _memoryData;
    unsigned int _maskedData;
public:
    LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};
