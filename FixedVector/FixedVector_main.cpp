// Main file for vector array
//
#include <iostream>
#include <cassert>
#include "FixedVector.h"

using namespace std;

int main() {
    // instantiate new FixedVector objects
    FixedVector<int> intNums(10);
    int count = 1;

    // add elements into VectorArray
    for (int i = 0; i < 10; i++) {
        intNums.set(i, count);
        count++;
    }

    // array get length test
    cout << "Testing getLength() function";
    assert(intNums.getLength() == 10);
    cout << "-->PASSED" << endl;

    // array empty test
    cout << "Checking if intNums is empty()";
    assert(intNums.is_empty() == false);
    cout << "-->PASSED" << endl;

    // get function test
    cout << "Testing get() function";
    assert(intNums.get(0) == 1);
    cout << "-->PASSED" << endl;

    // set function test
    int testNum = 100;
    cout << "Testing set() function";
    intNums.set(0, testNum);
    assert(intNums.get(0) == testNum);
    cout << "-->PASSED" << endl;

    // overloaded operator test
    cout << "Testing overloaded operator";
    assert(intNums[0] = 100);
    cout << "-->PASSED" << endl;

    // copy constructor test
    cout << "Testing copy constructor";
    FixedVector<int> intNumsCopy(intNums);
    assert(intNumsCopy.get(0) == 100);
    cout << "-->PASSED" << endl;
}
