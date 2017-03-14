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


