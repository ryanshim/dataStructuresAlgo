// Header file for a fixed vector
//
#pragma once
#include <stdexcept>

using namespace std;

template <typename E>
class FixedVector {
    public:
        FixedVector();                      // default constructor
        FixedVector(int len);               // constructor w/ length param
        FixedVector(const FixedVector& a);  // copy constructor
        ~FixedVector();                     // destructor
        int getLength();                    // return length of vector
        bool is_empty();                    // is vector empty?
        E& get(int index);                  // returns element stored at index
        void set(int index, E& value);      // set value at given index
        E& operator[](int index);           // overload [] operator
    private:
        int length;     // length of vector
        E *vectorArray; // pointer to vectorArray
};

// default constructor
template <typename E>
FixedVector<E>::FixedVector() {
    length = 0;
    vectorArray = new E[0];
}

// constructor w/ length param
template <typename E>
FixedVector<E>::FixedVector(int len) {
    if (len < 0) throw length_error("length cannot be < 0");
    length = len;
    vectorArray = new E[len];
}

// copy constructor
template <typename E>
FixedVector<E>::FixedVector(const FixedVector& a) {
    length = a.length;
    vectorArray = new E[length];
    // copy a's elements into new array
    for (int i = 0; i < length; i++) {
        vectorArray[i] = a.vectorArray[i];
    }
}

// destructor
template <typename E>
FixedVector<E>::~FixedVector() {
    delete [] vectorArray;
}

// return length of vector
template <typename E>
int FixedVector<E>::getLength() {
    return length;
}

// is vector empty?
template <typename E>
bool FixedVector<E>::is_empty() {
    return (length == 0);
}

// return element stored at index
template <typename E>
E& FixedVector<E>::get(int index) {
    if (index < 0 || index >= length) throw range_error("Index out of bounds");
    return vectorArray[index];
}

// set value at given index
template <typename E>
void FixedVector<E>::set(int index, E& value) {
    if (index < 0 || index >= length) throw range_error("Index out of bounds");
    vectorArray[index] = value;
}

// overload [] operator
template <typename E>
E& FixedVector<E>::operator[](int index) {
    if (index < 0 || index >= length) throw range_error("Index out of bounds");
    return get(index);
}



