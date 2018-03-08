// Main for testing mergesort implementation
#include <iostream>
#include <vector>
#include <ctime>
#include "MergeSort.h"

#define NUM_ELTS 10

int main() {

    srand(time(NULL));      // RNG seed

    std::vector<int> xVect; // create an empty vector
    std::vector<int> sortedVect;

    // populate vector with random numbers b/t 1 to 10
    for (int i = 0; i < NUM_ELTS; i++) {
        xVect.push_back(i);
        //xVect.push_back(rand() % 10 + 1);
    }

    sortedVect = mergeSort(xVect);

    for (int j = 0; j < NUM_ELTS; j++) {
        std::cout << sortedVect[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}
