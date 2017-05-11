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

    cout << "ROOT: " << BST1.getRoot() << endl;

    if (BST1.findValue(1)) {
        cout << "Found value: 1" << endl;
    }
    else {
        cout << "Value '1' not found" << endl;
    }

    return 0;
}
