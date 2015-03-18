//
//  FileIO.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#ifndef __processor_calculator__FileIO__
#define __processor_calculator__FileIO__

#include <iostream>
#include "Queue.h"

class FileIO {
private:
    FILE*   _inputFP;
    FILE*   _outputFP;
    
public:
    FileIO();
    ~FileIO();
    
public:
    Queue*  ReadInstruction();
    void    SaveResult(int regNumber, int result, char operate,
                       int operand1, int operand2);
    void    SaveResult(int regNumber, int result);
    
    
};

#endif /* defined(__processor_calculator__FileIO__) */
