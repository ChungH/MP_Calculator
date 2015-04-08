//
//  Store.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Store.h"
#include "Instructor.h"

//StoreByte class
StoreByte::StoreByte(unsigned int rs, unsigned int rt, unsigned int immediate) : I_Instruction(rs,rt,immediate){
    
}

bool StoreByte::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned int memoryIndex = (rsData+_immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = memoryData & 0xffffff00;
    unsigned int maskedrtData = rtData & 0x000000ff;
    
    unsigned int resultData = maskedMemoryData | maskedrtData;
    
    Instructor::SetDataToMemory(memoryIndex, resultData);
    
    return false;
}

//StoreConditional class
//추가 구현 필요
StoreConditional::StoreConditional(unsigned int rs, unsigned int rt, unsigned int immediate) : I_Instruction(rs,rt,immediate){
    
}

bool StoreConditional::Excution(){
    return false;
}

//StoreHalfword class
StoreHalfword::StoreHalfword(unsigned int rs, unsigned int rt, unsigned int immediate): I_Instruction(rs,rt,immediate){
    
}

bool StoreHalfword::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned int memoryIndex = (rsData+_immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = memoryData & 0xffff0000;
    unsigned int maskedrtData = rtData & 0x0000ffff;
    
    unsigned int resultData = maskedMemoryData | maskedrtData;
    
    Instructor::SetDataToMemory(memoryIndex, resultData);
    
    return false;
}

//StoreWord class
StoreWord::StoreWord(unsigned int rs, unsigned int rt, unsigned int immediate) : I_Instruction(rs, rt, immediate){
    
}

bool StoreWord::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int rtData = Instructor::GetDataFromRegister(_rt);
    unsigned int memoryIndex = (rsData+_immediate)/4;
    
    Instructor::SetDataToMemory(memoryIndex, rtData);
    
    return false;
}

