// header file for an ArrayQueue
// Queue based on a circular array
//
#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>
class ArrayQueue {
        enum {DEF_CAPACITY = 100};
    public:
        ArrayQueue(int cap = DEF_CAPACITY); // constructor
        int size() const;                   // return num items in queue
        bool empty() const;                 // is stack empty?
        const E& front() const;             // get top element
        void enqueue(const E& e);           // add to back of queue
        void dequeue();                     // remove from front of queue
        void printAll();                    // print all elements on stack
    private:
        E* Q;           // array of queue elements
        int capacity;   // capacity of queue
        int f;          // index of front element
        int r;          // index of cell just after last element
        int n;          // number of elements
};

// constructor
template <typename E>
ArrayQueue<E>::ArrayQueue(int cap) {
   Q = new E[cap];
   capacity = cap;
   f = 0;
   r = 0;
   n = 0;
}

// return num items in queue
template <typename E>
int ArrayQueue<E>::size() const {
    return n;
}

// empty stack check
template <typename E>
bool ArrayQueue<E>::empty() const {
    return (n == 0);
}

// get top element
template <typename E>
const E& ArrayQueue<E>::front() const {
    if (empty()) throw length_error("Calling front() on empty queue");
    return Q[f];
}

// add to back of queue
template <typename E>
void ArrayQueue<E>::enqueue(const E& e) {
    if (size() == capacity) throw length_error("Enqueue() called on full queue");
    Q[r] = e;
    r = (r + 1) % capacity;
    n++;
}

// remove from front of queue
template <typename E>
void ArrayQueue<E>::dequeue() {
    if (size() == 0) throw length_error("Dequeue() called on empty queue");
    f = (f + 1) % capacity;
    n--;
}

// print all elements on stack
// note: we use the same method used to dequeue to
// print queue elements
template <typename E>
void ArrayQueue<E>::printAll() {
    if (empty()) throw length_error("printAll() called on empty queue");
    cout << "Elements in Queue: ";
    int front = f;
    for (int i = 0; i < n; i++) {
        cout << "{" << Q[front] << "} ";
        front = (front + 1) % capacity;
    }
    cout << endl;
}


