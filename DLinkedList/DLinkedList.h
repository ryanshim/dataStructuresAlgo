// Header file for DLinkedList.h
//
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template <typename E> class DLinkedList;

template <typename E>
class DNode {
    private:
        E* elem;                        // node's element
        DNode<E> *next;                 // next node
        DNode<E> *prev;                 // previous node
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
        DNode<E> *header;   // header sentinel node
        DNode<E> *trailer;  // trailer sentinel node
    protected:
        void add(DNode<E> *v, const E& e);  // insert new node before v
        void remove(DNode<E> *v);           // remove node v
};

#endif
