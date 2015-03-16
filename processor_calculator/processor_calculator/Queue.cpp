//
//  Queue.cpp
//
//
//  Created by LeeChungHee on 2015. 3. 15
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Queue.h"

Queue* Queue::CreateQueue(){
    Queue* queue = new Queue;

    if(queue) {
        queue->_count = 0;
        queue->_front = queue->_rear = NULL;
    }
    
    return queue;
}

void Queue::Enqueue(Queue* queue, Node* node){
    node->SetNext(NULL);
    if (queue->_front == NULL) {
        queue->_front = queue->_rear = node;
        queue->_count++;
    }
    else {
        queue->_rear->SetNext(node);
        queue->_rear = node;
        queue->_count++;
    }
}

void* Queue::Dequeue(Queue* queue){
    if(queue->_front == NULL){
        return 0;
    }
    void* data = queue->_front->GetData();
    queue->_front = queue->_front->GetNext();
    queue->_count--;
    return data;
}

void Queue::DestroyQueue(Queue* queue){
    while (queue->_front != NULL) {
        Node* tmp = queue->_front->GetNext();
        delete (queue->_front);
        queue->_front = tmp;
    }
    delete (queue);
}

bool Queue::isEmpty(){
    if(_front == NULL)
        return true;

    return false;
}



