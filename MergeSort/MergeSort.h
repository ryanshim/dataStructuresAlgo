// Merge sort header file
#pragma once
#include <iostream>
#include <vector>

template <typename E>
std::vector<E> merge(std::vector<E> L, std::vector<E> R);   // forward declaration

template <typename E>
std::vector<E> mergeSort(std::vector<E> a) {
    if (a.size() <= 1) {
        return a;
    }
    else {
        unsigned half = a.size() / 2;

        // L, R = <DIVIDE V INTO TWO INSTANCES OF ROUGHLY EQUAL SIZE>
        std::vector<E> L;
        std::vector<E> R;
        for (unsigned i = 0; i < half; i++) {
            L.push_back(a[i]);
        }

        for (unsigned i = half; i < a.size(); i++) {
            R.push_back(a[i]);
        }

        std::vector<E> sortedL, sortedR, sortedV;

        // sorted_L = mergeSort(L)
        sortedL = mergeSort(L);

        // sorted_R = mergeSort(R)
        sortedR = mergeSort(R);

        // sorted_V = <COMBINE sorted_L WITH sorted_R>
        sortedV = merge(sortedL, sortedR);

        // return sorted_V
        return sortedV;
    }
}

template <typename E>
std::vector<E> merge(std::vector<E> L, std::vector<E> R) {
    std::vector<E> v;
    unsigned li = 0;
    unsigned ri = 0;

    while (li < L.size() && ri < R.size()) {
        if (L[li] <= R[ri]) {
            v.push_back(L[li]);
            li++;
        }
        else {
            v.push_back(R[ri]);
            ri++;
        }
    }

    // only one of these loops will execute
    for (; li < L.size(); li++) {
        v.push_back(L[li]);
    }
    for (; ri < R.size(); ri++) {
        v.push_back(R[ri]);
    }
    
    return v;
}


