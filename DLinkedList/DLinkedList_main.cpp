// Main function for Doubly Linked List implementation
//
#include "DLinkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    DLinkedList<int> intNums;
    int testNum = 0;

    // add elements
    for (int i = 100; i < 600; i += 100) {
        intNums.addBack(i);
    }
    testNum = intNums.front(); 
    assert(testNum == 100);

    return 0;
}
