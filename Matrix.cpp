#include <iostream>
#include <string>
#include <climits>
#include "Matrix.h"
#include "Graph.h"

using namespace std;

bool isNodeViable(int u, int n){
    return (u < n && u >= 0);
}


Matrix::Matrix(int n_){
    n = n_;
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = INT_MAX;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
}

void Matrix::addEdge(int u, int v, int w){
    if(!isNodeViable(u, n) || !isNodeViable(v, n)) throw domain_error("Added nodes not included in the graph");
    arr[u][v] = w;
}

int Matrix::getWeight(int u, int v){
    if(!isNodeViable(u, n) || !isNodeViable(v, n)) throw domain_error("Chosen nodes not included in the graph");
    return arr[u][v];
}

void Matrix::setWeight(int u, int v, int w){
    if(!isNodeViable(u, n) || !isNodeViable(v, n)) throw domain_error("Chosen nodes not included in the graph");
    arr[u][v] = w;
}

bool Matrix::exists(int u, int v){
    return arr[u][v] != INT_MAX;
}

void Matrix::show(){
    cout << "\n\t";
    for(int j = 0; j < n; j++){
        cout << j << "\t";
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << i << "\t";
        for(int j = 0; j < n; j++){
            int x = arr[i][j];
            if(x==INT_MAX)cout << "-\t";
            else cout << x << "\t";
        }
        cout << "\n";
    }
}