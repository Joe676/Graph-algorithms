#ifndef LIST_H
#define LIST_H

#pragma once

class Node{
    private:
        int v;
        int w;
        Node* next;
    public:
        Node();
        Node(int v_, int w_);
        Node(int v_, int w_, Node* n);

        void setV(int v_);
        int getV();

        void setW(int w_);
        int getW();

        void setNext(Node* n);
        Node* getNext();
};

class List{
    protected:
        Node* head;
        Node* tail;
        int len;

    public:
        List();
        ~List();

        int getLength();
        void insertLast(int v, int w);
        bool remove(int v);
        bool contains(int v);
        void setWeight(int v, int w);
        Node* find(int v);
        Node* getHead();
        Node* getTail();
        void show();
};

class GraphList{
    private:
        List* arr;
        int n;
    public:
        GraphList(int n_);
        ~GraphList();

        void addEdge(int u, int v, int w);
        void removeEdge(int u, int v);
        bool exists(int u, int v);
        int getWeight(int u, int v);
        void setWeight(int u, int v, int w);
        List* getNeighbours(int u);
        void show();
};


#endif