#include "GenericArray.h"
#include <iostream>

int main() {
    GenericArray<int> intArray;

    intArray.addElement(10);
    intArray.addElement(20);
    intArray.addElement(30);
    intArray.addElement(40);

    std::cout << "Size of array: " << intArray.size() << std::endl;
    std::cout << "Sum of array: " << intArray.sum() << std::endl;
    std::cout << "Maximum value: " << intArray.max() << std::endl;
    std::cout << "Minimum value: " << intArray.min() << std::endl;

    int* slicedArray = intArray.slice(1, 3);
    std::cout << "Sliced array: ";
    for (int i = 0; i < 3; i++) {
        std::cout << slicedArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] slicedArray;

    return 0;
}
