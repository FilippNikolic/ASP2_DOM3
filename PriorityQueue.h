//
// Created by nfili on 25/12/2022.
//

#ifndef MAIN_CPP_PRIORITYQUEUE_H
#define MAIN_CPP_PRIORITYQUEUE_H


#include <iostream>

using namespace std;

#include "Heap.h"

class PriorityQueue {
    Heap heap;
public:
    explicit PriorityQueue(int size) : heap(size) {}

    int get() const { return heap.peek(); }

    int remove() { return heap.deleteKey(); }

    PriorityQueue &insert(int k) {
            heap.insert(k);
        return *this; 
    }

    bool isEmpty() const { return heap.getSize() == 0; }

    bool isFull() const

      { return heap.getCapacity() == heap.getSize(); }

};


#endif //MAIN_CPP_PRIORITYQUEUE_H
