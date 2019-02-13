// Singly Linked List header file
// NOTE: Minimal implementation
//
#ifndef SLINKEDLIST_HPP_
#define SLINKEDLIST_HPP_

#include <stdexcept>

template <typename E>
class Node {
  public:
    Node(const E& e, Node<E> *nxt) 
      : elem(e), next(nxt) {}
    E elem;
    Node<E>* next;
};

template <typename E>
class SLinkedList {
  public:
    SLinkedList();					    // constructor
    ~SLinkedList();					    // destructor
    bool empty() const;         // is list empty?
    E& front();                 // return front element
    void add_front(const E& e);  // add e to front of list
    void remove_front();				  // remove front element
    int size() const;				    // list size
  private:
    Node<E> *head;
    int n;
};

// Constructor
template <typename E>
SLinkedList<E>::SLinkedList()
  : head(nullptr), n(0) {}

// Destructor
template <typename E>
SLinkedList<E>::~SLinkedList() {
  while (!empty()) {
    remove_front();
  }
}

// Check if the linked list is empty.
template <typename E>
bool SLinkedList<E>::empty() const {
  return (n == 0);
}

// Return the number of elements in the linked list.
template <typename E>
int SLinkedList<E>::size() const {
  return n;
}

// Return the value of the front element.
template <typename E>
E& SLinkedList<E>::front() {
  return head->elem;
}

// Add an element to the front of the linked list.
template <typename E>
void SLinkedList<E>::add_front(const E& e) {
  if (head == nullptr) {
    head = new Node<E>(e, nullptr);
  } else {
    head = new Node<E>(e, head);
  }
  n++;
}

// Remove an element at the front of the linked list.
template <typename E>
void SLinkedList<E>::remove_front() {
  if (head == nullptr) 
    throw std::length_error("Cannot remove from empty list.");
  Node<E> *nodeptr = head;
  head = head->next;
  delete nodeptr;
  n--;
}

#endif
