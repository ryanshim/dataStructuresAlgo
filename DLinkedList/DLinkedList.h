// Header file for DLinkedList.h
//
#pragma once
#include <stdexcept>

using namespace std;

template <typename E> class DLinkedList;

template <typename E>
class DNode {
    private:
        E elem;                        // node's element
        DNode<E>* next;                 // next node
        DNode<E>* prev;                 // previous node
        friend class DLinkedList<E>;    // provide access for DLinkedList class
};

template <typename E>
class DLinkedList {
    public:
        DLinkedList();                  // constructor
        ~DLinkedList();                 // destructor 
        bool empty() const;             // is list empty?
        E& front();                     // return list front node element
        E& back();                      // return list back node element
        void addFront(const E& e);      // add new node to front
        void addBack(const E& e);       // add new node to back
        void removeFront();             // remove front node
        void removeBack();              // remove back node
        int size() const;               // return num of elements in list 
    private:
        int n;              // number of items
        DNode<E>* header;   // header sentinel node
        DNode<E>* trailer;  // trailer sentinel node
    protected:
        void add(DNode<E>* v, const E& e);  // insert new node before v
        void remove(DNode<E>* v);           // remove node v
};

// constructor
template <typename E>
DLinkedList<E>::DLinkedList() {
    n = 0;
    header = new DNode<E>;  // create sentinels
    trailer = new DNode<E>;
    header->next = trailer; // point sentinels to each other
    trailer->prev = header;
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
    return header->next->elem;
}

// return back element
template <typename E>
E& DLinkedList<E>::back() {
    if (empty()) throw length_error("Empty List");
    return trailer->prev->elem;
}

// add new node to front
template <typename E>
void DLinkedList<E>::addFront(const E& e) {
    add(header->next, e);
}

// add new node to back
template <typename E>
void DLinkedList<E>::addBack(const E& e) {
    add(trailer, e);
}

// remove front node
template <typename E>
void DLinkedList<E>::removeFront() {
    if (empty()) throw length_error("Empty List");
    remove(header->next);
}

// remove back node
template <typename E>
void DLinkedList<E>::removeBack() {
    if (empty()) throw length_error("Empty List");
    remove(trailer->prev);
}

// return num elements in list
template <typename E>
int DLinkedList<E>::size() const {
    return n;
}

// add new node to front
template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) {
    DNode<E>* u = new DNode<E>; // create new node, u
    u->elem = e;                // set u's elem to e
    u->next = v;                // link u between v and v's prev 
    u->prev = v->prev;
    v->prev->next = u;          // set the node's next (before u) as u
    v->prev = u;                // set v's prev to u
    n++;
}

// remove node v
template <typename E>
void DLinkedList<E>::remove(DNode<E>* v) {
    DNode<E>* u = v->prev;      // predecessor
    DNode<E>* w = v->next;      // successor
    u->next = w;          // unlink v
    w->prev = u;
    delete v;                   // delete old node
    n--;
}

