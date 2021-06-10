#ifndef MATRIX_H
#define MATRIX_H

#pragma once

class Matrix{
    private:
        int n;
        int** arr;
    public:
        Matrix(int n_);
        ~Matrix();
        void addEdge(int u, int v, int w);
        bool exists(int u, int v);
        int getWeight(int u, int v);
        void setWeight(int u, int v, int w);
        void show();
};

#endif
