#include "Edge.h"

Edge::Edge(int u, int v, int w){
    start = u;
    end = v;
    weight = w;
}

int Edge::getStart(){
    return start;
}

void Edge::setStart(int u){
    start = u;
}

int Edge::getEnd(){
    return end;
}

void Edge::setEnd(int v){
    end = v;
}

int Edge::getWeight(){
    return weight;
}

void Edge::setWeight(int w){
    weight = w;
}
