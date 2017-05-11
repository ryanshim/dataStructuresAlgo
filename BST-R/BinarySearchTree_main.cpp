// Binary search tree main file
//
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree<int> BST1;

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
    cout << "SIZE: " << BST1.size() << endl;

    return 0;
}
