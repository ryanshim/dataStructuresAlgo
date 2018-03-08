// Binary search tree main file
//
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree<int> BST1;

    // test findValue() exception
    //BST1.findValue(3);

    BST1.insertNode(11);
    BST1.insertNode(3);
    BST1.insertNode(1);
    BST1.insertNode(10);
    BST1.insertNode(4);

    cout << "ROOT: " << BST1.getRoot() << endl;

    // search for value 1
    if (BST1.findValue(1)) {
        cout << "Found value: 1" << endl;
    }
    else {
        cout << "Value '1' not found" << endl;
    }

    // search for value 2
    if (BST1.findValue(2)) {
        cout << "Found value: 2" << endl;
    }
    else {
        cout << "Value '2' not found" << endl;
    }

    // search for value 4 
    if (BST1.findValue(4)) {
        cout << "Found value: 4" << endl;
    }
    else {
        cout << "Value '4' not found" << endl;
    }

    // test internal node removal
    BST1.removeNode(10);
    // search for value 10
    if (BST1.findValue(10)) {
        cout << "Found value: 10" << endl;
    }
    else {
        cout << "Value '10' not found" << endl;
    }   

    // search for value 4 
    if (BST1.findValue(4)) {
        cout << "Found value: 4" << endl;
    }
    else {
        cout << "Value '4' not found" << endl;
    }

    // test external node removal
    BST1.removeNode(4);
    // search for value 4 
    if (BST1.findValue(4)) {
        cout << "Found value: 4" << endl;
    }
    else {
        cout << "Value '4' not found" << endl;
    }

    // test removal of nonexistent node
    BST1.removeNode(5);

    return 0;
}
