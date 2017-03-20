// Main function for testing ArrayStack class
//
#include <iostream>
#include <cassert>
#include "ArrayStack.h"

using namespace std;

int main() {
    // instantiate new array stack object
    ArrayStack<int> stackIntNums(10);

    cout << "Testing empty() function for empty stack";
    assert(stackIntNums.empty() == true);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing push() function";
    for (int i = 0; i < 10; i++) {
        stackIntNums.push(i);
    }
    cout << "-->PASSED" << endl << endl;

    cout << "Testing size() function";
    assert(stackIntNums.size() == 10);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing empty() function for filled stack";
    assert(stackIntNums.empty() == false);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing top() function";
    assert(stackIntNums.top() == 9);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing pop() function";
    stackIntNums.pop();
    assert(stackIntNums.top() == 8);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing printAll() function";
    stackIntNums.printAll();
    cout << "-->PASSED" << endl << endl;

    return 0;
}
