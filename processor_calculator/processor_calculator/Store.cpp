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
    
}

bool StoreByte::Execution(){
    _maskedrtData = _rtData & 0x000000ff;
    
    
    return false;
}

void StoreByte::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = _memoryData & 0xffffff00;
    
    _resultData = maskedMemoryData | _maskedrtData;
    Instructor::SetDataToMemory(memoryIndex, _resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : StoreByte \nM[R[%d]+%d](7:0) = R[%d](7:0) =>\nM[%d] = %d\n==================================\n",_rs,_immediate,_rt, memoryIndex, _resultData);
    Instructor::AppendLog(logBuf);
    
}
void StoreByte::WriteBack(){
    
    
}


//StoreConditional class
//추가 구현 필요
StoreConditional::StoreConditional(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : I_Instruction(rs,rt,immediate,rsData,rtData){
    
}

bool StoreConditional::Execution(){
    return false;
}
void StoreConditional::MemoryAccess(){
    
}
void StoreConditional::WriteBack(){
    
}

//StoreHalfword class
StoreHalfword::StoreHalfword(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData): I_Instruction(rs,rt,immediate,rsData,rtData){
    
}

bool StoreHalfword::Execution(){
    _maskedrtData = _rtData & 0x0000ffff;
    

    return false;
}
void StoreHalfword::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedMemoryData = _memoryData & 0xffff0000;
    
    _resultData = maskedMemoryData | _maskedrtData;
    
    Instructor::SetDataToMemory(memoryIndex, _resultData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : StoreHalfWord \nM[R[%d]+%d](15:0) = R[%d](15:0) =>\nM[%d] = %d\n==================================\n",_rs,_immediate,_rt,memoryIndex, _resultData);
    Instructor::AppendLog(logBuf);
    
    
    
}
void StoreHalfword::WriteBack(){
    
}

//StoreWord class
StoreWord::StoreWord(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : I_Instruction(rs, rt, immediate,rsData,rtData){
    
}

bool StoreWord::Execution(){

    return false;
}
void StoreWord::MemoryAccess(){
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    
    Instructor::SetDataToMemory(memoryIndex, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : StoreWord \nM[R[%d]+%d] = R[%d] =>\nM[%d] = %d\n==================================\n",_rs,_immediate,_rt,memoryIndex, _rtData);
    Instructor::AppendLog(logBuf);
    
}

void StoreWord::WriteBack(){
    
}

