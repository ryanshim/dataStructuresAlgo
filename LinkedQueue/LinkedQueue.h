// header file for LinkedQueue
// implementation of a queue based on a linked list
//
#pragma once
#include <iostream>
#include <stdexcept>
#include "DLinkedList_cp.h"

using namespace std;

template <typename E>
class LinkedQueue {
    public:
        LinkedQueue();              // constructor
        int size() const;           // return size of queue
        bool empty() const;         // is queue empty?
        E& front();                 // return front element in queue
        void enqueue(const E& e);   // enqueue element at rear
        void dequeue();             // dequeue element at front
        void printFront();          // print front element
    private:
        DLinkedList<E> D;           // doubly linked list of elements
        int n;                      // num elements in queue
};

// constructor
template <typename E>
LinkedQueue<E>::LinkedQueue() {
    DLinkedList<E> D;
    n = 0;
}

// return size of queue
template <typename E>
int LinkedQueue<E>::size() const {
    return n;
}

// empty queue check 
template <typename E>
bool LinkedQueue<E>::empty() const {
    return (size() == 0);
}

// front element in queue
template <typename E>
E& LinkedQueue<E>::front() {
    if (empty()) throw length_error("front() called on empty queue");
    return  D.front();
}

// enqueue element at rear
template <typename E>
void LinkedQueue<E>::enqueue(const E& e) {
    D.addBack(e);
    n++;
}

// dequeue element at front
template <typename E>
void LinkedQueue<E>::dequeue() {
    if (empty()) throw length_error("dequeue() called on empty queue");
    D.removeFront();
    n--;
}

// print front element in queue
template <typename E>
void LinkedQueue<E>::printFront() {
    if (empty()) throw length_error("printAll() called on empty queue");
    cout << "Front of queue: {" << D.front() << "}" << endl;
}
