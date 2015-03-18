//
//  Queue.h
//
//
//  Created by LeeChungHee on 2015. 3. 15..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#pragma once
#include <iostream>
#include <stdlib.h>
#include "Node.h"

class Queue{
private:
    int     _count;
    Node*   _front;
    Node*   _rear;
public:
    ~Queue();
    
public:
    Queue*  CreateQueue();
    void    Enqueue(Queue* queue, Node* node);
    void*   Dequeue(Queue* queue);
    void    DestroyQueue(Queue* queue);
    bool    isEmpty();

};


