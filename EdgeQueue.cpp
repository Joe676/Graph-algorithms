#include "Edge.h"
#include "EdgeQueue.h"
#include <stdexcept>

EdgeQueue::EdgeQueue(int len){
    edges = new Edge*[len];
    length = len;
    heap_size = 0;
}

EdgeQueue::~EdgeQueue(){
    for(int i = 0; i < heap_size; i++){
        delete edges[i];
    }
    delete[] edges;
}

int EdgeQueue::right(int i){
    return 2*i + 2;
}

int EdgeQueue::left(int i){
    return 2*i + 1;
}

int EdgeQueue::parent(int i){
    return (i+1)/2 - 1;
}

void EdgeQueue::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l <= heap_size && edges[l]->getWeight() < edges[smallest]->getWeight())smallest = l;
    if(r <= heap_size && edges[r]->getWeight() < edges[smallest]->getWeight())smallest = r;
    if(smallest != i){
        Edge* tmp = edges[i];
        edges[i] = edges[smallest];
        edges[smallest] = tmp;
        minHeapify(smallest);
    }
}

bool EdgeQueue::isEmpty(){
    return heap_size == 0;
}

void EdgeQueue::put(Edge* e){
    if(heap_size == length )throw std::out_of_range("The heap is full");
    int newIndex = heap_size;
    heap_size++;
    edges[newIndex] = e;

    while(newIndex > 0 && edges[newIndex]->getWeight() < edges[parent(newIndex)]->getWeight()){
        Edge* tmp = edges[parent(newIndex)];
        edges[parent(newIndex)] = edges[newIndex];
        edges[newIndex] = tmp;

        newIndex = parent(newIndex);
    }
}

Edge* EdgeQueue::extractMin(){
    Edge* e = edges[0];
    heap_size--;
    edges[0] = edges[heap_size];
    minHeapify(0);
    return e;
}