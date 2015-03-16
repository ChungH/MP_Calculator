//
//  FileIO.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "FileIO.h"

FileIO::FileIO(){
    
    _inputFP  = NULL;
    _outputFP = NULL;
//    
//    _inputFP = fopen("/Users/ChungH/Desktop/instruction.txt", "r");
//    if(_inputFP==NULL){
//        fclose(_inputFP);
//        return;
//    }
    
    _outputFP = fopen("/Users/ChungH/Desktop/result.txt", "w");
    if(_outputFP==NULL){
        fclose(_inputFP);
        fclose(_outputFP);
        return;
    }
}

Queue* FileIO::ReadInstruction(){
    
    if(_inputFP==NULL){
        _inputFP = fopen("/Users/ChungH/Desktop/instruction.txt", "r");
    }
    Queue* queue;
    queue = queue->CreateQueue();
    
    while (!feof(_inputFP)){
        char instruction[100];
        fgets(instruction, 99, _inputFP);
        
        Node* node = new Node;
        node->SaveData(instruction);
        queue->Enqueue(queue, node);
    }
    
    return queue;
}

void FileIO::SaveResult(int regNumber, int result, char operate,
                        int operand1, int operand2){
    
    if(_outputFP==NULL){
     _outputFP = fopen("/Users/ChungH/Desktop/result.txt", "w");
    }
    
    fprintf(_outputFP, "R%d : %d = %d %c %d\n",regNumber,result, operand1, operate, operand2);
}

void FileIO::SaveResult(int regNumber, int result){
    
    if(_outputFP==NULL){
        _outputFP = fopen("/Users/ChungH/Desktop/result.txt", "w");
    }
    fprintf(_outputFP, "R%d : %d\n",regNumber, result);
    
}

