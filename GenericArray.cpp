#include "GenericArray.h"
#include <stdexcept>

template <typename T>
GenericArray<T>::GenericArray() : array(nullptr), capacity(0) {}

template <typename T>
GenericArray<T>::~GenericArray() {
    delete[] array;
}

template <typename T>
void GenericArray<T>::addElement(T element) {
    T* newArray = new T[capacity + 1];
    for (int i = 0; i < capacity; i++) {
        newArray[i] = array[i];
    }
    newArray[capacity] = element;
    delete[] array;
    array = newArray;
    capacity++;
}

template <typename T>
T GenericArray<T>::at(int index) {
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template <typename T>
int GenericArray<T>::size() {
    return capacity;
}

template <typename T>
T GenericArray<T>::sum() {
    T total = 0;
    for (int i = 0; i < capacity; i++) {
        total += array[i];
    }
    return total;
}

template <typename T>
T GenericArray<T>::max() {
    if (capacity == 0) {
        throw std::runtime_error("Array is empty");
    }
    T maxValue = array[0];
    for (int i = 1; i < capacity; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }
    return maxValue;
}

template <typename T>
T GenericArray<T>::min() {
    if (capacity == 0) {
        throw std::runtime_error("Array is empty");
    }
    T minValue = array[0];
    for (int i = 1; i < capacity; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        }
    }
    return minValue;
}

template <typename T>
T* GenericArray<T>::slice(int begin, int end) {
    if (begin < 0 || end >= capacity || begin > end) {
        throw std::out_of_range("Slice bounds are invalid");
    }
    int newSize = end - begin + 1;
    T* newArray = new T[newSize];
    for (int i = 0; i < newSize; i++) {
        newArray[i] = array[begin + i];
    }
    return newArray;
}

template class GenericArray<int>;
template class GenericArray<float>;
template class GenericArray<double>;
