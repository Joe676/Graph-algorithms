#include "Graph.h"
#include "PriorityQueue.h"
#include <climits>
#include <iostream>



void Graph::PrimMatrix(int** out){
    int* d = new int[n];
    int* prev = new int[n];
    bool* inMST = new bool[n];
    for(int i = 0; i < n; i++){
        d[i] = INT_MAX;
        prev[i] = -1;
        inMST[i] = false;
    }
    PriorityQueue Q(qE);

    d[0] = 0;
    Q.put(d[0], 0);

    while(!Q.isEmpty()){
        int u = Q.extractDataMin();
        if(inMST[u])continue;
        inMST[u] = true;
        for(int v = 0; v < n; v++){
            if(!matrix->exists(u, v))continue;
            int weight = matrix->getWeight(u, v);
            if(!inMST[v] && weight < d[v]){
                prev[v] = u;
                d[v] = weight;
                Q.put(d[v], v);
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        out[i][0] = i+1;
        out[i][1] = prev[i+1];
        out[i][2] = matrix->getWeight(i+1, prev[i+1]);
    }

    delete[] d;
    delete[] prev;
    delete[] inMST;
}

void Graph::PrimList(int** out){
    int* d = new int[n];
    int* prev = new int[n];
    bool* inMST = new bool[n];
    for(int i = 0; i < n; i++){
        d[i] = INT_MAX;
        prev[i] = -1;
        inMST[i] = false;
    }
    PriorityQueue Q(qE);

    d[0] = 0;
    Q.put(d[0], 0);

    while(!Q.isEmpty()){
        int u = Q.extractDataMin();
        inMST[u] = true;

        Node* current = list->getNeighbours(u)->getHead();
        while(current != nullptr){
            int v = current->getV();
            int w = current->getW();
            if(!inMST[v] && d[v] > w){
                prev[v] = u;
                d[v] = w;
                Q.put(d[v], v);
            }
            current = current->getNext();
        }
    }
    for(int i = 0; i < n-1; i++){
        out[i][0] = i+1;
        out[i][1] = prev[i+1];
        out[i][2] = list->getWeight(i+1, prev[i+1]);
    }
    delete[] d;
    delete[] prev;
    delete[] inMST;
}