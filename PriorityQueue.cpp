#include <stdexcept>
#include "PriorityQueue.h"
#include "Graph.h"

PriorityQueue::PriorityQueue(int len){
    keys = new int[len];
    data = new int[len];
    heap_size = 0;
    length = len;
}

PriorityQueue::~PriorityQueue(){
    delete[] keys;
    delete[] data;
}

int PriorityQueue::right(int i){
    return 2*i + 2;
}

int PriorityQueue::left(int i){
    return 2*i + 1;
}

int PriorityQueue::parent(int i){
    return (i+1)/2 - 1;
}

void PriorityQueue::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l <= heap_size && keys[l] < keys[smallest])smallest = l;
    if(r <= heap_size && keys[r] < keys[smallest])smallest = r;
    if(smallest != i){
        int tmp = keys[i];
        keys[i] = keys[smallest];
        keys[smallest] = tmp;
        
        tmp = data[i];
        data[i] = data[smallest];
        data[smallest] = tmp;
        minHeapify(smallest);
    }
}

void PriorityQueue::put(int k, int d){
    if(heap_size == length)throw std::out_of_range("The heap is full");
    int newIndex = heap_size;
    heap_size++;
    keys[newIndex] = k;
    data[newIndex] = d;

    while(newIndex > 0 && keys[newIndex] < keys[parent(newIndex)]){
        int tmp = keys[parent(newIndex)];
        keys[parent(newIndex)] = keys[newIndex];
        keys[newIndex] = tmp;

        tmp = data[parent(newIndex)];
        data[parent(newIndex)] = data[newIndex];
        data[newIndex] = tmp;

        newIndex = parent(newIndex);
    }
    
}

int PriorityQueue::extractDataMin(){
    // int key = keys[0];
    int dat = data[0];
    heap_size--;
    keys[0] = keys[heap_size];
    data[0] = data[heap_size];
    minHeapify(0);
    return dat;
}

bool PriorityQueue::isEmpty(){
    return heap_size == 0;
}