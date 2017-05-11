// BinarySearchTree header file
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E> class BinarySearchTree;   // forward declaration

template <typename E>
class BNode {
    private:
        E elem;
        BNode<E>* parent;
        BNode<E>* left;
        BNode<E>* right;
        friend class BinarySearchTree<E>;          // access for BinarySearchTree class
};

template <typename E>
class BinarySearchTree {
    public:
        BinarySearchTree();                     // constructor
        ~BinarySearchTree();                    // destructor
        int size() const;                       // number of entries
        bool empty() const;                     // check if empty BST
        E& getRoot() const;                     // element of root node
        void insertNode(const E& e);            // insert new node
        void removeNode(BNode<E>* v);           // remove specified node
        bool findValue(const E& e) const;
    private:
        BNode<E>* root;                         // root node ptr
        int n;                                  // num elements
};

// constructor
template <typename E>
BinarySearchTree<E>::BinarySearchTree() {
    root = NULL;
    n = 0;
}

// destructor
template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
    // code destructor here
}

// return num elements
template <typename E>
int BinarySearchTree<E>::size() const {
    return n;
}

// check if empty BST
template <typename E>
bool BinarySearchTree<E>::empty() const {
    return (n == 0);
}

// return root element
template <typename E>
E& BinarySearchTree<E>::getRoot() const {
    return root->elem;
}

// find the value given in BST
template <typename E>
bool BinarySearchTree<E>::findValue(const E& e) const {
    if (empty()) throw length_error("findValue called on empty BST");
    BNode<E>* nodePtr;
    nodePtr = root;
        while (nodePtr) {
            if (e == nodePtr->elem) {
                return true;
            }
            else if (e < nodePtr->elem) {
                nodePtr = nodePtr->left;
            }
            else {
                nodePtr = nodePtr->right;
            }
        }
    return false; 
}

// insert new node
template <typename E>
void BinarySearchTree<E>::insertNode(const E& e) {
    if (empty()) {
        BNode<E>* v = new BNode<E>;
        v->parent = NULL; 
        v->left = NULL;
        v->right = NULL;
        v->elem = e;
        root = v;
        n++;
    }
    else {
        BNode<E>* nodePtr;
        BNode<E>* curParent;
        nodePtr = root;
        while (nodePtr) {
            if (e < nodePtr->elem) {
                curParent = nodePtr;
                nodePtr = nodePtr->left;
            }
            else if (e > nodePtr->elem) {
                curParent = nodePtr;
                nodePtr = nodePtr->right;
            }
            else {
                cout << "Same element found" << endl;
                return;
            }
        }
        // create new node
        BNode<E>* v = new BNode<E>;
        v->elem = e;
        v->parent = curParent;
        v->left = NULL;
        v->right = NULL;

        // update parent's pointers
        if (e < v->parent->elem)  {
            v->parent->left = v;
        }
        else {
            v->parent->right = v;
        }

        // increment number of nodes
        n++;
    }
}
