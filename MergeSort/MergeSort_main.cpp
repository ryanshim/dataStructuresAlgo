// Main for testing mergesort implementation
#include "MergeSort.h"
#include <ctime>

#define NUM_ELTS 20 

int main() {

    srand(time(NULL));      // RNG seed

    std::vector<int> xVect; // create an empty vector
    std::vector<int> sortedVect;
    int value;

    // populate vector with random numbers b/t 1 to 10
    std::cout << "Unordered Vector:" << std::endl;;
    for (int i = 0; i < NUM_ELTS; i++) {
        value = rand() % 10 + 1;
        std::cout << value << " ";
        xVect.push_back(value);
    }
    std::cout << std::endl << std::endl;;

    sortedVect = mergeSort(xVect);

    std::cout << "Ordered Vector:" << std::endl;
    for (unsigned i = 0; i < sortedVect.size(); i++) {
        std::cout << sortedVect[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
