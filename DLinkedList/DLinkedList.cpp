// Contains header functions for DLinkedList.h
//
#pragma once
#include "DLinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// constructor
template <typename E>
DLinkedList<E>::DLinkedList() {
    n = 0;
    header = new DNode<E>;  // create sentinels
    trailer = new DNode<E>;
    header->next = trailer; // point sentinels to each other
    trailer-prev = header;
}

// destructor
template <typename E>
DLinkedList<E>::~DLinkedList() {
    while (!empty()) {
        removeFront(); 
    }
    delete header;
    delete trailer;
}

// list empty check
template <typename E>
bool DLinkedList<E>::empty() const {
    return (header->next == trailer);
}

// return front element
template <typename E>
E& DLinkedList<E>::front() {
    if (empty()) throw length_error("Empty List");
    return (header->next->elem);
}

// return back element
template <typename E>
E& DLinkedList<E>::back() {
    if (empty()) throw length_error("Empty List");
    return (trailer->prev->elem);
}

// add new node to front
template <typename E>
void DLinkedList<E>::add(DNode<E> *v, const E& e) {
    DNode<E>* u = new DNode<E>; // create new node, u
    u->elem = e;                // set u's elem to e
    u->next = v;                // link u between v and v's prev 
    u->prev = v->prev;
    v->prev->next = u;          // set the node's next (before u) as u
    v->prev = u;                // set v's prev to u
}










