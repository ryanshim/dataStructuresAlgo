// header file for LinkedStack
// LinkedStack is a Linked List based stack
//
#pragma once
#include <iostream>
#include <stdexcept>
#include "SLinkedList_cp.h"

using namespace std;

template <typename E>
class LinkedStack {
    public:
        LinkedStack();          // constructor
        int size() const;       // num items in stack
        bool empty() const;     // is stack empty?
        E& top();               // return top element
        void push(const E& e);  // push element onto stack
        void pop();             // pop element off stack
        void printTop();        // print top element of stack
    private:
        SLinkedList<E> stack;   // linked-list used for stack
        int numElements;        // current num elements in stack
};

// constructor
template <typename E>
LinkedStack<E>::LinkedStack() {
    SLinkedList<E> stack;            // instantiate new linked list for stack
    numElements = 0;
}

// return num items in stack
template <typename E>
int LinkedStack<E>::size() const {
    return numElements;
}

// empty stack check function
template <typename E>
bool LinkedStack<E>::empty() const {
    return (numElements == 0);
}

// return top element
template <typename E>
E& LinkedStack<E>::top() {
    if (empty()) throw length_error("top() called on empty stack");
    return stack.front();
}

// stack push function
template <typename E>
void LinkedStack<E>::push(const E& e) {
    stack.addFront(e);
    numElements++;
}

// stack pop function
template <typename E>
void LinkedStack<E>::pop() {
    if (empty()) throw length_error("pop() called on empty stack");
    stack.removeFront();
    numElements--;
}

// print top element
template <typename E>
void LinkedStack<E>::printTop() {
    if (empty()) throw length_error("printTop() called on empty stack");
    cout << "Current element at top of stack: " << stack.front() << endl;
}


