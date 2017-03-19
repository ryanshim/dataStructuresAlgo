// Main function for Doubly Linked List implementation
//
#include "DLinkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    DLinkedList<int> intNums;
    int testNumFront = 0;
    int testNumBack = 0;

    // add elements
    for (int i = 100; i < 600; i += 100) {
        intNums.addBack(i);
    }
    testNumFront = intNums.front(); 
    testNumBack = intNums.back();
    cout << "Current front element: " << testNumFront << endl;
    cout << "Current back element: " << testNumBack << endl;
    assert(testNumFront == 100);
    assert(testNumBack == 500);

    intNums.removeFront();  // remove front element
    intNums.removeBack();   // remove back element

    testNumFront = intNums.front(); 
    testNumBack = intNums.back();
    cout << "Current front element: " << testNumFront << endl;
    cout << "Current back element: " << testNumBack << endl;
    assert(testNumFront == 200);
    assert(testNumBack == 400);

    intNums.removeFront();  // remove front element

    testNumFront = intNums.front(); 
    testNumBack = intNums.back();
    cout << "Current front element: " << testNumFront << endl;
    cout << "Current back element: " << testNumBack << endl;
    assert(testNumFront == 300);
    assert(testNumBack == 400);

    return 0;
}
