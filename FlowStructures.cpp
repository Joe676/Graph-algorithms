#include "FlowStructures.h"

int Queue::getFrontV(){
    return head->getV();
}

int Queue::getFrontW(){
    return head->getW();
}

void Queue::dequeue(){
    Node* tmp = head;
    head = head->getNext();
    delete tmp;
    len--;
}

void Queue::enqueue(int v, int w){
    insertLast(v, w);
}

bool Queue::isEmpty(){
    return len == 0;
}

int Stack::getTopV(){
    return tail->getV();
}

int Stack::getTopW(){
    return tail->getW();
}

void Stack::pop(){
    if(len-- == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node* curr = head;
    while(curr->getNext()!=tail)curr = curr->getNext();
    delete curr->getNext();
    curr->setNext(nullptr);
    tail = curr;
}

void Stack::put(int v, int w){
    insertLast(v, w);
}

bool Stack::isEmpty(){
    return len == 0;
}

