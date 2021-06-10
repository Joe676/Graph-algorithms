#ifndef GRAPH_H
#define GRAPH_H

#pragma once
#include "Matrix.h"
#include "List.h"

class Graph{
    private:
        Matrix* matrix;
        GraphList* list;
        int n;
        int qE;
    
    public:
        Graph(int n_);
        ~Graph();

        void addEdge(int u, int v, int w);
        void removeEdge(int u, int v);
        
        void setN(int n_);

        void generate(int n_, int density, bool isDirected, int lo, int hi);

        Matrix* getMatrix();
        GraphList* getList();

        //MST - out is a 2D array of size [n-1][3] for storing list of edges of the MST

        void PrimMatrix(int** out);
        void PrimList(int** out);

        void KruskalMatrix(int** out);
        void KruskalList(int** out);

        //routes
        void DijkstraMatrix(int** out, int s);
        void DijkstraList(int** out, int s);

        bool FordBellmanMatrix(int** out, int s);
        bool FordBellmanList(int** out, int s);

        //maximum flow
        int FordFulkersonDFSMatrix(Matrix* capacity, int s, int t);
        int FordFulkersonDFSList(GraphList* capacity, int s, int t);
        int FordFulkersonBFSMatrix(Matrix* capacity, int s, int t);
        int FordFulkersonBFSList(GraphList* capacity, int s, int t);

        //show
        void showMatrix();
        void showList();

};

int min(int a, int b);
bool isNodeViable(int u, int n);

#endif