#include "Graph.h"
#include <iostream>
#include <climits>

bool Graph::FordBellmanMatrix(int** out, int s){ //2d array - out[i][0] == d[i], out[i][1] == prev[i]
    // int* d = new int[n];
    // int* prev = new int[n];
    //init
    for(int i = 0; i < n; i++){
        // d[i] = INT_MAX;
        // prev[i] = -1;
        out[i][0] = INT_MAX;
        out[i][1] = -1;
    }
    // d[0] = 0;
    out[s][0] = 0;

    bool relaxed = false;
    for(int i = 0; i < n-1; i++){
        relaxed = false;
        for(int u = 0; u < n; u++){
            // if(d[u] == INT_MAX)continue;
            if(out[u][0] == INT_MAX)continue;
            for(int v = 0; v < n; v++){
                if(!matrix->exists(u, v))continue;
                int weight = matrix->getWeight(u, v);
                // if(weight != 0 && weight + d[u] < d[v]){
                if(weight + out[u][0] < out[v][0]){
                    // prev[v] = u;
                    // d[v] = weight + d[u];
                    out[v][1] = u;
                    out[v][0] = weight + out[u][0];
                    relaxed = true;
                }
            }
        }
        if(!relaxed)break; 
    }
    if(relaxed){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                // if(matrix->getWeight(u, v) != 0 && d[u] + matrix->getWeight(u, v) < d[v]){
                if(matrix->exists(u, v) && out[u][0] + matrix->getWeight(u, v) < out[v][0]){
                    return false;
                }
            }
        }
    }
    // delete[] d;
    // delete[] prev;
    return true;
}

bool Graph::FordBellmanList(int** out, int s){ //2d array - out[i][0] == d[i], out[i][1] == prev[i]
    // int* d = new int[n];
    // int* prev = new int[n];
    //init
    for(int i = 0; i < n; i++){
        // d[i] = INT_MAX;
        // prev[i] = -1;
        out[i][0] = INT_MAX;
        out[i][1] = -1;
    }
    // d[0] = 0;
    out[s][0] = 0;

    bool relaxed = false;
    for(int i = 0; i < n-1; i++){
        relaxed = false;
        for(int u = 0; u < n; u++){
            // if(d[u] == INT_MAX)continue;
            if(out[u][0] == INT_MAX)continue;
            Node* current = list->getNeighbours(u)->getHead();
            while(current != nullptr){
                int v = current->getV();
                int w = current->getW();
                // if(w + d[u] < d[v]){
                //     prev[v] = u;
                //     d[v] = w + d[u];
                //     relaxed = true;
                // }
                if(w + out[u][0] < out[v][0]){
                    out[v][1] = u;
                    out[v][0] = w + out[u][0];
                    relaxed = true;
                }
                current = current->getNext();
            }
        }
        if(!relaxed)break; 
    }
    if(relaxed){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(list->exists(u, v) && out[u][0] + list->getWeight(u, v) < out[v][0]){
                    return false;
                }
            }
        }
    }

    // delete[] d;
    // delete[] prev;
    return true;
}