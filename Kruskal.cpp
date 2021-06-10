#include "Graph.h"
#include "EdgeQueue.h"
#include <iostream>

int Find(int* set, int x){
    if(set[x]!=x)set[x] = Find(set, set[x]);
    return set[x];
}

void Union(int* set, int* rank, int x, int y){
    int a = Find(set, x);
    int b = Find(set, y);
    if (rank[a] < rank[b]){
        set[a] = b;
    }
    else{
        set[b] = a;
    }
    if (rank[a] = rank[b]){
        rank[a] = rank[a]+1;
    }
}

void Graph::KruskalMatrix(int** out){
    int* set = new int[n];
    int* rank = new int[n];
    for(int i = 0; i < n; i++){
        set[i] = i;
        rank[i] = 0;
    }
    EdgeQueue *eq = new EdgeQueue(qE);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){ //We need to check just one half of the matrix because of the symmetry
            if(matrix->exists(i, j)){
                eq->put(new Edge(i, j, matrix->getWeight(i, j)));
            }
        }
    }
    
    int addedEdges = 0;
    Edge* edge;
    while(addedEdges < n-1 && !eq->isEmpty()){
        edge = eq->extractMin();
        if(Find(set, edge->getStart()) != Find(set, edge->getEnd())){
            // out[addedEdges] = new int[3];
            out[addedEdges][0] = edge->getStart();
            out[addedEdges][1] = edge->getEnd();
            out[addedEdges][2] = edge->getWeight();
            Union(set, rank, edge->getStart(), edge->getEnd());
            addedEdges++;
        }
        delete edge;
    }
    delete eq;
    delete[] set;
    delete[] rank;
}

void Graph::KruskalList(int** out){
    int* set = new int[n];
    int* rank = new int[n];
    for(int i = 0; i < n; i++){
        set[i] = i;
        rank[i] = 0;
    }
    EdgeQueue eq(qE);
    for(int i = 0; i < n; i++){
        Node* current = list->getNeighbours(i)->getHead();
        while(current != nullptr){
            eq.put(new Edge(i, current->getV(), current->getW()));
            current = current->getNext();
        }
    }
    
    int addedEdges = 0;
    Edge* edge;
    while(addedEdges < n-1){
        edge = eq.extractMin();
        if(Find(set, edge->getStart()) != Find(set, edge->getEnd())){
            // out[addedEdges] = new int[3];
            out[addedEdges][0] = edge->getStart();
            out[addedEdges][1] = edge->getEnd();
            out[addedEdges][2] = edge->getWeight();

            Union(set, rank, edge->getStart(), edge->getEnd());
            addedEdges++;
        }
    }

    delete[] set;
    delete[] rank;
}