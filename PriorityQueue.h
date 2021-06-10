#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#pragma once

class PriorityQueue{
    private:
        int* keys;
        int* data;
        int length;
        int heap_size;

        int right(int i);
        int left(int i);
        int parent(int i);

        void minHeapify(int i);
    public:
        PriorityQueue(int len);
        ~PriorityQueue();

        bool isEmpty();
        void put(int k, int d);
        int extractDataMin();
};

#endif