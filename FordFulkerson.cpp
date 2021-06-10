#include "Graph.h"
#include "FlowStructures.h"
#include <climits>
#include <iostream>
//      LINKS
//https://github.com/juanplopes/icpc/blob/master/uva/820.cpp
//https://stackoverflow.com/questions/16740629/ford-fulkerson-algorithm-with-depth-first-search
//https://cp-algorithms.com/graph/edmonds_karp.html#toc-tgt-2
int min(int a, int b){
    return a < b ? a : b;
}

int bfsMatrix(int s, int t, int n, int* prev, Matrix* capacity){
    for(int i = 0; i < n; i++){
        prev[i] = -1;
    }

    Queue q;
    q.enqueue(s, INT_MAX);

    while(!q.isEmpty()){
        int current = q.getFrontV();
        int flow = q.getFrontW();
        q.dequeue();

        for(int next = 0; next < n; next++){
            if(prev[next] == -1 && capacity->exists(current, next) && capacity->getWeight(current, next) != 0){
                prev[next] = current;
                int newFlow = min(flow, capacity->getWeight(current, next));
                if(next == t) return newFlow;
                q.enqueue(next, newFlow);
            }
        }
    }
    return 0;
}

int bfsList(int s, int t, int n, int* prev, GraphList* capacity){
    for(int i = 0; i < n; i++){
        prev[i] = -1;
    }

    Queue q;
    q.enqueue(s, INT_MAX);

    while(!q.isEmpty()){
        int current = q.getFrontV();
        int flow = q.getFrontW();
        q.dequeue();

        Node* next = capacity->getNeighbours(current)->getHead();
        while(next != nullptr){
            int v = next->getV();
            int w = next->getW();
            if(prev[v] == -1 && w != 0){
                prev[v] = current;
                int newFlow = min(flow, w);
                if(v == t) return newFlow;
                q.enqueue(v, newFlow);
            }
            next = next->getNext();
        }
    }
    return 0;
}

int dfsMatrix(int s, int t, int n, int* prev, Matrix* capacity){
    for(int i = 0; i < n; i++){
        prev[i] = -1;
    }

    Stack st;
    st.put(s, INT_MAX);

    while(!st.isEmpty()){
        int current = st.getTopV();
        int flow = st.getTopW();
        st.pop();

        for(int next = 0; next < n; next++){
            if(prev[next] == -1 && capacity->exists(current, next) && capacity->getWeight(current, next) != 0 ){
                prev[next] = current;
                int newFlow = min(flow, capacity->getWeight(current, next));
                if(next == t) return newFlow;
                st.put(next, newFlow);
            }
        }
    }
    return 0;
}

int dfsList(int s, int t, int n, int* prev, GraphList* capacity){
    for(int i = 0; i < n; i++){
        prev[i] = -1;
    }

    Stack st;
    st.put(s, INT_MAX);

    while(!st.isEmpty()){
        int current = st.getTopV();
        int flow = st.getTopW();
        st.pop();

        Node* next = capacity->getNeighbours(current)->getHead();
        while(next != nullptr){
            int v = next->getV();
            int w = next->getW();
            if(prev[v] == -1 && w != 0){
                prev[v] = current;
                int newFlow = min(flow, w);
                if(v == t) return newFlow;
                st.put(v, newFlow);
            }
            next = next->getNext();
        }
    }
    return 0;
}

int Graph::FordFulkersonDFSMatrix(Matrix* capacity, int s, int t){
    int flow = 0;
    // Matrix capacity(n);
    int* prev = new int[n];
    int newFlow;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix->exists(i, j)){
                int w = matrix->getWeight(i, j);
                capacity->setWeight(i, j, w);
            }else{
                capacity->setWeight(i, j, 0);
            }
        }
    }

    while(newFlow = dfsMatrix(s, t, n, prev, capacity)){
        flow += newFlow;
        int current = t;
        while(current != s){
            int p = prev[current];
            capacity->setWeight(p, current, capacity->getWeight(p, current)-newFlow);
            capacity->setWeight(current, p, capacity->getWeight(current, p)+newFlow);
            current = p;
        }
    }
    delete[] prev;
    return flow;
}

int Graph::FordFulkersonDFSList(GraphList* capacity, int s, int t){
    int flow = 0;
    // GraphList capacity(n);
    int* prev = new int[n];
    int newFlow;

    //Copy and create residual network with back edges
    for(int u = 0; u < n; u++){
        Node* current = list->getNeighbours(u)->getHead();
        while(current != nullptr){
            int v = current->getV();
            if(!capacity->exists(u, v)){
                capacity->addEdge(u, v, current->getW());
                if(!capacity->exists(v, u)){
                    capacity->addEdge(v, u, 0);
                }
            }
            else{
                capacity->setWeight(u, v, capacity->getWeight(u, v)+current->getW());
            }
            current = current->getNext();
        }
    }

    while(newFlow = dfsList(s, t, n, prev, capacity)){
        flow += newFlow;
        int current = t;
        while(current != s){
            int p = prev[current];
            capacity->setWeight(p, current, capacity->getWeight(p, current)-newFlow);
            capacity->setWeight(current, p, capacity->getWeight(current, p)+newFlow);
            current = p;
        }
    }
    delete[] prev;
    return flow;
}

int Graph::FordFulkersonBFSMatrix(Matrix* capacity, int s, int t){
    int flow = 0;
    // Matrix capacity(n);
    int* prev = new int[n];
    int newFlow;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix->exists(i, j)){
                int w = matrix->getWeight(i, j);
                capacity->setWeight(i, j, w);
            }else{
                capacity->setWeight(i, j, 0);
            }
        }
    }

    while(newFlow = bfsMatrix(s, t, n, prev, capacity)){
        flow += newFlow;
        int current = t;
        while(current != s){
            int p = prev[current];
            capacity->setWeight(p, current, capacity->getWeight(p, current)-newFlow);
            capacity->setWeight(current, p, capacity->getWeight(current, p)+newFlow);
            current = p;
        }
    }
    delete[] prev;
    return flow;
}

int Graph::FordFulkersonBFSList(GraphList* capacity, int s, int t){
    int flow = 0;
    // GraphList capacity(n);
    int* prev = new int[n];
    int newFlow;

    //Copy and create residual network with back edges
    for(int u = 0; u < n; u++){
        Node* current = list->getNeighbours(u)->getHead();
        while(current != nullptr){
            int v = current->getV();
            if(!capacity->exists(u, v)){
                capacity->addEdge(u, v, current->getW());
                if(!capacity->exists(v, u)){
                    capacity->addEdge(v, u, 0);
                }
            }
            else{
                capacity->setWeight(u, v, capacity->getWeight(u, v)+current->getW());
            }
            current = current->getNext();
        }
    }

    while(newFlow = bfsList(s, t, n, prev, capacity)){
        flow += newFlow;
        int current = t;
        while(current != s){
            int p = prev[current];
            capacity->setWeight(p, current, capacity->getWeight(p, current)-newFlow);
            capacity->setWeight(current, p, capacity->getWeight(current, p)+newFlow);
            current = p;
        }
    }
    delete[] prev;
    return flow;
}
