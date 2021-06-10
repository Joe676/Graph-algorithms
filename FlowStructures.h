#ifndef FLOWSTRUCTURES_H
#define FLOWSTRUCTURES_H

#pragma once
#include "List.h"

class Queue: private List{
    public:
        int getFrontV();
        int getFrontW();
        void dequeue();
        void enqueue(int v, int w);
        bool isEmpty();
};

class Stack: private List{
    public:
        int getTopV();
        int getTopW();
        void pop();
        void put(int v, int w);
        bool isEmpty();
};

#endif