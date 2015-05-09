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
    unsigned int _memoryData;
    unsigned int _maskedrtData;
    unsigned int _resultData;
public:
    StoreByte(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class StoreConditional : public I_Instruction {
public:
    unsigned int _memoryData;
    unsigned int _maskedrtData;
    unsigned int _resultData;
public:
    StoreConditional(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class StoreHalfword : public I_Instruction {
public:
    unsigned int _memoryData;
    unsigned int _maskedrtData;
    unsigned int _resultData;
public:
    StoreHalfword(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class StoreWord : public I_Instruction {
public:
    StoreWord(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};
