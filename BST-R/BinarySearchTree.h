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
        void removeNode(const E& e);            // remove specified node
        BNode<E>* findValue(const E& e) const;  // check if value is in bst
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
BNode<E>* BinarySearchTree<E>::findValue(const E& e) const {
    if (empty()) throw length_error("findValue called on empty BST");
    BNode<E>* nodePtr;
    nodePtr = root;
        while (nodePtr) {
            if (e == nodePtr->elem) {
                return nodePtr;
            }
            else if (e < nodePtr->elem) {
                nodePtr = nodePtr->left;
            }
            else {
                nodePtr = nodePtr->right;
            }
        }
    return nodePtr;
}

// insert new node
// there's a lot of repeated code
// will need to create a helper function
template <typename E>
void BinarySearchTree<E>::insertNode(const E& e) {
    if (empty()) {
        BNode<E>* v = new BNode<E>;
        BNode<E>* l = new BNode<E>;
        BNode<E>* r = new BNode<E>;

        // set node v's properties
        v->parent = NULL; 
        v->left = l;
        v->right = r;
        v->elem = e;

        // populate v's nodes w/ empty nodes
        l->left = NULL;
        l->right = NULL;
        l->parent = v;

        r->left = NULL;
        r->right = NULL;
        r->parent = v;

        root = v;   // set v as root
        n++;        // increment node count
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
        BNode<E>* l = new BNode<E>;
        BNode<E>* r = new BNode<E>;

        // set node v's properties
        v->elem = e;
        v->parent = curParent;
        v->left = l;
        v->right = r;

        // populate v's nodes w/ empty nodes
        l->left = NULL;
        l->right = NULL;
        l->parent = v;

        r->left = NULL;
        r->right = NULL;
        r->parent = v;

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

// remove a node from tree
template <typename E>
void BinarySearchTree<E>::removeNode(const E& e) {
    if (n == 0) throw length_error("removeNode called on empty tree");

    BNode<E>* v = findValue(e);
    if (v) {
        BNode<E>* nodePtr = v;

        if (v->right->elem) {       
            nodePtr = v->right; // traverse one node to the right
            while (nodePtr) {   // traverse left until NULL left ptr
                nodePtr = nodePtr->left;
            }

            // set v's parent left/right ptr with replacement node
            if (e < v->parent->elem) {
                v->parent->left = nodePtr->parent;
            }
            else {
                v->parent->right = nodePtr->parent;
            }

            nodePtr->parent->parent = v->parent; // set replacement's parent w/ v's parent

        }
        else {
            nodePtr = v->left;              // set nodePtr to be v's left
            v->parent->right = nodePtr;     // set v's parent's right element to v's left node
            nodePtr->parent = v->parent;    // set v's left parent to be v's parent
        }
        delete v;
    }
    else {
        cout << "Value " << e << " not in tree." << endl;
    }
}
