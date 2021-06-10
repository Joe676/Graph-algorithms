#ifndef EDGE_H
#define EDGE_H

#pragma once

class Edge{
    private:
        int start;
        int end;
        int weight;
    public:
        Edge(int u, int v, int w);

        int getStart();
        void setStart(int u);

        int getEnd();
        void setEnd(int v);

        int getWeight();
        void setWeight(int w);
};

#endif