#ifndef EDGEQUEUE_H
#define EDGEQUEUE_H

#pragma once
#include "Edge.h"

class EdgeQueue{
    private:
        Edge** edges;
        int length;
        int heap_size;

        int right(int i);
        int left(int i);
        int parent(int i);

        void minHeapify(int i);

    public:
        EdgeQueue(int len);
        ~EdgeQueue();

        bool isEmpty();
        void put(Edge* e);
        Edge* extractMin();
};

#endif