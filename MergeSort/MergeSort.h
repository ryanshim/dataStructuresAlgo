// Merge sort header file
#pragma once
#include <iostream> // for editor, remove later
#include <vector>   // for editor, remove later
#include <stdexcept>

template <typename E>
std::vector<E> mergeSort(std::vector<E> a) {
    if (a.size() <= 1) {
        return a;
    }
    else {
        // L, R = <DIVIDE V INTO TWO INSTANCES OF ROUGHLY EQUAL SIZE>
        std::vector<E> L, R;
        for (unsigned i = 0; i < a.size() / 2; i++) {
            L.push_back(a[i]);
        }
        for (unsigned j = a.size() / 2; j < a.size(); j++) {
            R.push_back(a[j]);
        }

        std::vector<E> sortedL, sortedR, sortedV;

        // sorted_L = mergeSort(L)
        sortedL = mergeSort(L);

        // sorted_R = mergeSort(R)
        sortedR = mergeSort(R);

        // sorted_V = <COMBINE sorted_L WITH sorted_R>
        
        // return sorted_V
        return sortedV;
    }
}


