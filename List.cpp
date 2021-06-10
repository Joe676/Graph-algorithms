#include <iostream>
#include "List.h"
#include "Graph.h"

using namespace std;


//      GRAPH LIST METHODS

GraphList::GraphList(int n_){
    n = n_;
    arr = new List[n];
}

GraphList::~GraphList(){
    delete[] arr;
}

void GraphList::addEdge(int u, int v, int w){
    if(!isNodeViable(u, n) || !isNodeViable(v, n))throw domain_error("Added nodes not included in the graph");
    arr[u].insertLast(v, w);
}

void GraphList::removeEdge(int u, int v){
    if(!isNodeViable(u, n) || !isNodeViable(v, n))throw domain_error("Removed nodes not included in the graph");
    if(!arr[u].remove(v))throw std::domain_error("The removed edge is not in the graph");
}

bool GraphList::exists(int u, int v){
    return arr[u].contains(v);
}

int GraphList::getWeight(int u, int v){
    if(!isNodeViable(u, n) || !isNodeViable(v, n))throw domain_error("Chosen nodes not included in the graph");
    Node* n = arr[u].find(v);
    if(n == nullptr)throw std::domain_error("Can't get a weight of empty edge");
    return n->getW();
}

void GraphList::setWeight(int u, int v, int w){
    if(!isNodeViable(u, n) || !isNodeViable(v, n))throw domain_error("Chosen nodes not included in the graph");
    Node* n = arr[u].find(v);
    if(n == nullptr)throw std::domain_error("Can't set a weight of empty edge");
    n->setW(w);
}

List* GraphList::getNeighbours(int u){
    return &(arr[u]);
}

void GraphList::show(){
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        arr[i].show();
        cout << "\n";
    }
}

//      LIST METHODS

List::List(){
    head = nullptr;
    tail = nullptr;
    len = 0;
}

List::~List(){
    while(len > 0){
        Node* n = head;
        head = head->getNext();
        delete n;
        len--;
    }
}

int List::getLength(){
    return len;
}

void List::insertLast(int v, int w){
    if(len++ == 0){
        head = new Node(v, w);
        tail = head;
    }else{
        tail->setNext(new Node(v, w));
        tail = tail->getNext();
    }
}

bool List::remove(int v){
    Node* current = head;
    while(current->getNext() != nullptr && current->getNext()->getV() != v){
        current = current->getNext();
    }
    if(current->getNext() == nullptr) return false;
    if(current == head){
        head = head->getNext();
        delete current;
        len--;
        return true;
    }
    if(current->getNext() == tail) tail = current;
    Node* toDel = current->getNext();
    current->setNext(current->getNext()->getNext());
    delete toDel;
    len--;
    return true;
}

bool List::contains(int v){
    return find(v) != nullptr;
}

void List::setWeight(int v, int w){
    Node* n = find(v);
    if(n != nullptr) n->setW(w);
}

Node* List::find(int v){
    Node* current = head;
    while(current != nullptr && current->getV()!=v)current = current->getNext();
    return current;
}

Node* List::getHead(){
    return head;
}

Node* List::getTail(){
    return tail;
}

void List::show(){
    for(Node* current = head; current != nullptr; current = current->getNext()){
        cout  << "(" << current->getV() << ", " << current->getW() << ") ";
    }
    // cout << "\n";
}

//      NODE METHODS

Node::Node(){
    v = -1;
    w = 0;
    next = nullptr;
}

Node::Node(int v_, int w_){
    v = v_;
    w = w_;
    next = nullptr;
}

Node::Node(int v_, int w_, Node* n){
    v = v_;
    w = w_;
    next = n;
}

void Node::setV(int v_){
    v = v_;
}

int Node::getV(){
    return v;
}

void Node::setW(int w_){
    w = w_;
}

int Node::getW(){
    return w;
}

void Node::setNext(Node* n){
    next = n;
}

Node* Node::getNext(){
    return next;
}