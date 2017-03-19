// Main function for testing SNodeList
//
#include <iostream>
#include <cassert>
#include "SNodeList.h"

using namespace std;

int main() {
    SNodeList<int> lstIntNums;          // instantiate new SNodeList object

    // test addFront function
    cout << "Testing addFront() function";
    for (int i = 9; i >= 0; i--) {      // add elements to list
        lstIntNums.addFront(i);
    }
    cout << "-->PASSED" << endl << endl;

    // test empty function
    cout << "Testing empty() function";
    assert(lstIntNums.empty() == false);
    cout << "-->PASSED" << endl << endl;

     // test front function
    cout << "Testing front() function";
    assert(lstIntNums.front() == 0);
    cout << "-->PASSED" << endl << endl;

    // test removeFront function
    int testNum;
    testNum = 1;
    cout << "Testing removeFront() function";
    lstIntNums.removeFront();
    assert(lstIntNums.front() == testNum);
    cout << "-->PASSED" << endl << endl;

     // test size function
    cout << "Testing size() function";
    assert(lstIntNums.size() == 9);
    cout << "-->PASSED" << endl << endl;

    cout << "Testing iterator class for list traversal" << endl;
    for (SNodeList<int>::Iterator j = lstIntNums.begin(); j != lstIntNums.end(); ++j) {
        cout << j.get() << " ";
    }
    cout << endl;
    cout << "-->PASSED" << endl << endl;

    return 0;
}
