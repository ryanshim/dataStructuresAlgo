// main file for testing linked list
//
#include <iostream>
#include <cassert>
#include "LinkedQueue.h"

using namespace std;

int main() {
    LinkedQueue<int> intNumQueue;   // instantiate new queue object

    cout << "Testing enqueue() function";
    for (int i = 0; i < 10; i++) {
        intNumQueue.enqueue(i);
    }
    cout << "-->PASSED" << endl << endl;

    cout << "Testing size() function";
    assert(intNumQueue.size() == 10);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing empty() function";
    assert(intNumQueue.empty() == false);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing front() function";
    assert(intNumQueue.front() == 0);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing dequeue() function";
    intNumQueue.dequeue();
    assert(intNumQueue.front() == 1);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing printFront() function";
    intNumQueue.printFront();
    cout << "-->PASSED" << endl << endl;

    return 0;
}
