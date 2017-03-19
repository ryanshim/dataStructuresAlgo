// SNodeList Header file
// SNodeList is a singly linked list but also utilizes
// a nested iterator class for to demonstrate list traversals
//
#pragma once
#include <stdexcept>

using namespace std;

template <typename E> class SNodeList;  // forward declaration of SNodeList

template <typename E>
class SNode {
    private:
        E elem;                     // node's element value
        SNode<E> *next;             // ptr to next node
        friend class SNodeList<E>;  // provide access to SNodeList class
};

template <typename E>
class SNodeList {
    public:
        // provide nested class Iterator class within
        // SNodeList class for list traversals
        class Iterator {
            public:
                E& get() {                  // reference to element
                    return v->elem;
                }
                E& operator*() {            // ref to element via overloaded operator
                    return v->elem;
                }
                bool operator==(const Iterator& p) {    // equal to operator overload
                    return v == p.v;
                }
                bool operator!=(const Iterator& p) {    // not equal to operator overload
                    return v != p.v;
                }
                Iterator& operator++() {    // move to next position
                    v = v->next;
                    return *this;
                }
                friend class SNodeList;     // provide access to SNodeList

            private:
                SNode<E> *v;                // ptr to node
                Iterator(SNode<E> *u) {     // constructor from SNode
                    v = u;
                }
        };

    public:
        SNodeList();                // constructor
        ~SNodeList();               // destructor
        bool empty() const;         // is list empty?
        E& front();                 // return front element
        void addFront(const E& e);  // add new node to front of list
        void removeFront();         // remove front node
        int size() const;           // return size of list
        Iterator begin() const {    // beg. position of first node
            return Iterator(head);
        }        
        Iterator end() const {      // end position following last node
            return Iterator(NULL);
        }           
    private:
        SNode<E>* head;             // head of list
        int n;                      // num items
};

// SNodeList member function definitions
// constructor
template <typename E>
SNodeList<E>::SNodeList() {
    n = 0;
    head = NULL;
}

// destructor
template <typename E>
SNodeList<E>::~SNodeList() {
    while (!empty()) {
        removeFront();
    }
}

// empty list check
template <typename E>
bool SNodeList<E>::empty() const { 
    // return (n == 0);
    return (head == NULL);
}

// return front element
template <typename E>
E& SNodeList<E>::front() {
    return (head->elem);
}

// add new node to front of list
template <typename E>
void SNodeList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>;     // create new node
    v->elem = e;                    // set u's element to e
    v->next = head;                 // set u's next to current head
    head = v;                       // set head as u
    n++;
}

// remove front node
template <typename E>
void SNodeList<E>::removeFront() {
    if (empty()) throw length_error("Empty List");
    SNode<E>* old = head;   // old node to be deleted
    head = old->next;
    delete old;
    n--;
}

// return size of list
template <typename E>
int SNodeList<E>::size() const {
    return n;
}

