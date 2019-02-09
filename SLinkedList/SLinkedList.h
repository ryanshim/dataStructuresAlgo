// Singly Linked List
//
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E> class SLinkedList;	// forward declaration of SLinkedList

template <typename E>
class SNode {
    private:
        E elem;							// node's element
        SNode<E> *next;					// ptr to next node
        friend class SLinkedList<E>;	// provide access for SLinkedList class
};

template <typename E>
class SLinkedList {
    public:
        SLinkedList();					// constructor
        ~SLinkedList();					// destructor
        bool empty() const;				// is list empty?
        E& front();						// return front element
        void addFront(const E& e);		// add e to front of list
        void removeFront();				// remove front element
        int size() const;				// list size
    private:
        SNode<E> *head;					// head of list
        int n;							// number of elements
};

// constructor
template <typename E>
SLinkedList<E>::SLinkedList()
    : head(NULL), n(0) { }

// destructor
template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty()) {
        removeFront(); 
    }
}

// is list empty?
template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

// return front element
template <typename E>
E& SLinkedList<E>::front() {
	if (empty()) throw length_error("Empty List");
	return head->elem;
}

// add element to front of list
template <typename E>
void SLinkedList<E>::addFront(const E& e) {
	SNode<E> *v = new SNode<E>;		// create new node
	v->elem = e;					// set e as v's element
	v->next = head;					// set v's next as current head
	head = v;						// set v as current head
	n++;							// increment number of elements
}

// remove front element
template <typename E>
void SLinkedList<E>::removeFront() {
	SNode<E> *old = new SNode<E>;   // temp node to hold node to remove
    old = head;                     // set old to the current head
    head = old->next;               // unlink old's head from the list
    delete old;                     // delete the old node
    n--;
}

// list size
template <typename E>
int SLinkedList<E>::size() const {
	return n;
}
