// Main to test Singly Linked List
//
#include <iostream>
#include <cassert>
#include "SLinkedList.hpp"

using namespace std;

int main() {
  SLinkedList<int> intList;

  // insert elements
  int count = 100;
  while (count < 600) {
    intList.add_front(count);
    count += 100;
  }
  int testInt = intList.front(); 
  cout << "Current front element: " << testInt << endl;
  assert (testInt == 500);

  // delete a front element
  intList.remove_front(); 
  testInt = intList.front(); 
  cout << "Current front element: " << testInt << endl;
  assert (testInt == 400);

  // delete a front element
  intList.remove_front(); 
  testInt = intList.front(); 
  cout << "Current front element: " << testInt << endl;
  assert (testInt == 300);

  // delete a front element
  intList.remove_front(); 
  testInt = intList.front(); 
  cout << "Current front element: " << testInt << endl;
  assert (testInt == 200);

  // delete a front element
  intList.remove_front(); 
  testInt = intList.front(); 
  cout << "Current front element: " << testInt << endl;
  assert (testInt == 100);

  // delete a front element
  intList.remove_front(); 

  return 0;
}
