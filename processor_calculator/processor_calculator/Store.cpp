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
StoreByte::StoreByte(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : I_Instruction(rs,rt,immediate,rsData,rtData){
    _writeChk = false;
}

bool StoreByte::Execution(){
    _maskedrtData = _rtData & 0x000000ff;
    
    Instructor::AppendLog("SB,");
    return false;
}

void StoreByte::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = _memoryData & 0xffffff00;
    
    _resultData = maskedMemoryData | _maskedrtData;
    Instructor::SetDataToMemory(memoryIndex, _resultData);
    
    Instructor::AppendLog("SB,");
}
void StoreByte::WriteBack(){
    Instructor::AppendLog("SB,");
}


//StoreConditional class
//추가 구현 필요
StoreConditional::StoreConditional(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : I_Instruction(rs,rt,immediate,rsData,rtData){
    _writeChk = false;
}

bool StoreConditional::Execution(){
    Instructor::AppendLog("SC,");
    return false;
}
void StoreConditional::MemoryAccess(){
    Instructor::AppendLog("SC,");
}
void StoreConditional::WriteBack(){
    Instructor::AppendLog("SC,");
}

//StoreHalfword class
StoreHalfword::StoreHalfword(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData): I_Instruction(rs,rt,immediate,rsData,rtData){
    _writeChk = false;
}

bool StoreHalfword::Execution(){
    _maskedrtData = _rtData & 0x0000ffff;
    Instructor::AppendLog("SH,");
    return false;
}
void StoreHalfword::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = _memoryData & 0xffff0000;
    
    _resultData = maskedMemoryData | _maskedrtData;
    
    Instructor::SetDataToMemory(memoryIndex, _resultData);
    
    Instructor::AppendLog("SH,");
    
    
}
void StoreHalfword::WriteBack(){
    Instructor::AppendLog("SH,");
}

//StoreWord class
StoreWord::StoreWord(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : I_Instruction(rs, rt, immediate,rsData,rtData){
    _writeChk = false;
}

bool StoreWord::Execution(){
    Instructor::AppendLog("SW,");
    return false;
}
void StoreWord::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    
    Instructor::SetDataToMemory(memoryIndex, _rtData);
    
    Instructor::AppendLog("SW,");
    
}

void StoreWord::WriteBack(){
    Instructor::AppendLog("SW,");
}

