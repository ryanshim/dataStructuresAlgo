// main function for testing ArrayQueue
//
#include <iostream>
#include <cassert>
#include "ArrayQueue.h"

using namespace std;

int main() {
    ArrayQueue<int> intNumQueue(10);    // instantiate new ArrayQueue object

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

    cout << "Testing printAll() function";
    intNumQueue.printAll();
    cout << "-->PASSED" << endl << endl;

    return 0;
}
