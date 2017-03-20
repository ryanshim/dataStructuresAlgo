// Header file for ArrayStack
// Implementation of a stack using an array
//
#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename E>
class ArrayStack {
    enum {DEF_CAPACITY = 100};
    public:
        ArrayStack(int cap);    // constructor
        int size() const;       // return size of stack
        bool empty() const;     // is stack empty?
        const E& top() const;   // get top element
        void push(const E& e);  // push element on top of stack
        void pop();             // pop top element off stack
        void printAll();        // print all elements on top of stack
    private:
        E* S;                   // ptr to array
        int capacity;           // capacity of array
        int t;                  // index position of top of stack
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) { }

template <typename E>
int ArrayStack<E>::size() const {
    return t + 1; 
}

template <typename E>
bool ArrayStack<E>::empty() const {
    return (t < 0);
}

template <typename E>
const E& ArrayStack<E>::top() const {
    if (empty()) throw length_error("Empty Stack");
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
    if (size() == capacity) throw length_error("Full Stack");
    S[++t] = e;     // note: pre-increment operator used
}

template <typename E>
void ArrayStack<E>::pop() {
    if (t < 0) throw length_error("Empty Stack");
    t--;
}

template <typename E>
void ArrayStack<E>::printAll() {
    if (empty()) throw length_error("Empty Stack");
    // print from top down
    cout << endl;
    for (int i = t; i >= 0; i--) {
        cout << "[" << S[i] << "] ";
    }
    cout << endl;
    /*
    // print from bottom up
    for (int i = 0; i < t; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
    */
}
