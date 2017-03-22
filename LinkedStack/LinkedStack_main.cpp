// main function for LinkedStack testing
//
#include <iostream>
#include <cassert>
#include "LinkedStack.h"

using namespace std;

int main() {
    LinkedStack<int> intNumStack;       // instantiate new stack of ints

    cout << "Testing push() function";
    for (int i = 0; i < 10; i++) {
        intNumStack.push(i);
    }
    cout << "-->PASSED" << endl << endl;

    cout << "Testing size() function";
    assert(intNumStack.size() == 10);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing empty() function";
    assert(intNumStack.empty() == false);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing top() function";
    assert(intNumStack.top() == 9);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing pop() function";
    intNumStack.pop();
    assert(intNumStack.top() == 8);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing printTop() function" << endl;;
    intNumStack.printTop();
    cout << "-->PASSED" << endl;

    return 0;
}
