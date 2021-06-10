#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Matrix.h"
#include "Graph.h"

using namespace std;

Graph::Graph(int n_){
    matrix = new Matrix(n_);
    list = new GraphList(n_);
    n = n_;
    qE = 0;
}

Graph::~Graph(){
    delete matrix;
    delete list;
}

void Graph::addEdge(int u, int v, int w){
    qE++;
    try
    {
        matrix->addEdge(u, v, w);
        list->addEdge(u, v, w);
    }
    catch(const std::domain_error& e)
    {
        cout << "Cannot connect " << u << " and " << v << endl;
    }
    
}

void Graph::removeEdge(int u, int v){
    qE--;
    try
    {
        matrix->addEdge(u, v, 0);
        list->removeEdge(u, v);
    }
    catch(const std::domain_error& e){
        cout << "Cannot remove edge (" << u << ", " << v << ")" << endl;
    }
}

void Graph::setN(int n_){
    delete matrix;
    delete list;
    matrix = new Matrix(n_);
    list = new GraphList(n_);
    n = n_;
    qE = 0;
}

void Graph::showMatrix(){
    cout << "Adjacency Matrix: \n";
    matrix->show();
    cout << endl;
}

void Graph::showList(){
    cout << "Adjacency List: \n";
    list->show();
    cout << endl;
}

void Graph::generate(int n_, int density, bool isDirected, int lo, int hi){
    setN(n_);
    bool* inTree = new bool[n_];
    for(int i = 0; i < n_; i++){
        inTree[i] = false;
    }
    int e = n_ * (n_ - 1);
    if(!isDirected) e /= 2;
    e = e * density / 100;
    inTree[0] = true;
    for(int i = 0; i < n_-1; i++){
        int u, v, w;
        do{
            u = rand()%n_;
            v = rand()%n_;
        }while(!inTree[u] || inTree[v]);
        w = rand()%(hi-lo) + lo;
        inTree[v] = true;
        addEdge(u, v, w);
        if(!isDirected)addEdge(v, u, w);
    }
    for(int i = n_-1; i < e; i++){
        int u, v, w;
        do{
            u = rand()%n_;
            v = rand()%n_;
        }while(u == v || matrix->exists(u, v));
        do{w = rand()%(hi-lo) + lo;}while(w==0);
        addEdge(u, v, w);
        if(!isDirected)addEdge(v, u, w);
    }
    delete[] inTree;
}

Matrix* Graph::getMatrix(){
    return matrix;
}

GraphList* Graph::getList(){
    return list;
}