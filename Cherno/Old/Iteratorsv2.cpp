#include <iostream>
#include <vector>
#include "Vectors.h"
#include "ArrayDS.h"

int main() {
Vector<std::string> values;
values.PushBack("1");
values.PushBack("2");
values.PushBack("Manchester");
values.PushBack("4");
values.PushBack("5");

std::cout << "Not using iterators" << std::endl;
for (int i = 0; i < values.Size(); i++) {
    std::cout << values[i] << ", ";
}
std::cout << std::endl;

std::cout << "Range-based for loop" << std::endl;
for (auto& value : values) {
    std::cout << value << ", ";
}
std::cout << std::endl;

std::cout << "Itearator" << std::endl;
for (Vector<std::string>::Iterator it = values.begin(); it != values.end(); it++) {
    std::cout << *it << ", ";
}
std::cout << "\n-------------------------" << std::endl;

Array<int, 5> array = {0, 0, 0, 0, 0};  // Initialize all elements to 0
array[0] = 1;
array[1] = 2;

std::cout << "Array" << std::endl;
for (int i = 0; i < array.Size(); i++) {
    std::cout << array[i] << ", " << " index: " << i << std::endl;
}
std::cout << std::endl;

std::cout << "Range-based for loop" << std::endl;
for (auto& value : array) {
    std::cout << value << ", ";
}
std::cout << std::endl;

std::cout << "Iterator" << std::endl;
for (Array<int, 5>::Iterator it = array.begin(); it != array.end(); it++) {
    std::cout << *it << ", ";
}
std::cout << std::endl;

#if 0
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }

    for (int& value : vec) {
        std::cout << value << std::endl;
    }

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }
#endif
    return 0;
}