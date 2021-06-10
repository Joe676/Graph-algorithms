#include "Graph.h"
#include "PriorityQueue.h"
#include <climits>
#include <iostream>

void Graph::DijkstraMatrix(int** out, int s){//2d array - out[i][0] == d[i], out[i][1] == prev[i]
    // int* d = new int[n];
    // int* prev = new int[n];
    bool* vis = new bool[n];
    //init
    for(int i = 0; i < n; i++){
        // d[i] = INT_MAX;
        // prev[i] = -1;
        out[i][0] = INT_MAX;
        out[i][1] = -1;
        vis[i] = false;
    }
    PriorityQueue Q(qE);

    //d[0] = 0;
    //Q.put(d[0], 0)
    out[s][0] = 0;
    Q.put(out[s][0], s);

    while(!Q.isEmpty()){
        int u = Q.extractDataMin();
        if(vis[u])continue;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(!matrix->exists(u, v))continue;
            int weight = matrix->getWeight(u, v);
            // if(!vis[v] && weight + d[u] < d[v]){
            //     prev[v] = u;
            //     d[v] = weight + d[u];
            //     Q.put(d[v], v);
            // }
            if(!vis[v] && weight + out[u][0] < out[v][0]){
                out[v][1] = u;
                out[v][0] = weight + out[u][0];
                Q.put(out[v][0], v);
            }
        }
    }
    // delete[] d;
    // delete[] prev;
    delete[] vis;
}

void Graph::DijkstraList(int** out, int s){
    // int* d = new int[n];
    // int* prev = new int[n];
    bool* vis = new bool[n];
    //init
    for(int i = 0; i < n; i++){
        // d[i] = INT_MAX;
        // prev[i] = -1;
        out[i][0] = INT_MAX;
        out[i][1] = -1;
        vis[i] = false;
    }
    PriorityQueue Q(qE);

    // d[0] = 0;
    // Q.put(d[0], 0);
    out[s][0] = 0;
    Q.put(out[s][0], s);

    while(!Q.isEmpty()){
        int u = Q.extractDataMin();
        if(vis[u])continue;
        vis[u] = true;
        Node* current = list->getNeighbours(u)->getHead();
        while(current != nullptr){
            int v = current->getV();
            int w = current->getW();
            // if(!vis[v] && d[v] > w + d[u]){
            //     prev[v] = u;
            //     d[v] = w + d[u];
            //     Q.put(d[v], v);
            // }
            if(!vis[v] && out[v][0] > w + out[u][0]){
                out[v][1] = u;
                out[v][0] = w + out[u][0];
                Q.put(out[v][0], v);
            }
            current = current->getNext();
        }
    }

    // delete[] d;
    // delete[] prev;
    delete[] vis;
}