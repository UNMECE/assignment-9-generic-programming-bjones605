#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

template <typename T>
class GenericArray {
private:
    T* array;
    int capacity;

public:
    GenericArray();
    ~GenericArray();

    void addElement(T element);
    T at(int index);
    int size();
    T sum();
    T max();
    T min();
    T* slice(int begin, int end);
};

#endif // GENERICARRAY_H
