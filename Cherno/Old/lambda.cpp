#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <string>

template <size_t Size>
void FillArray(int (&arr)[Size]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < Size; i++) {
        arr[i] = distribution(gen);
    } 
}

int main() {
    std::vector<int> values = { 1, 2, 5, 110, 23 };
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value >= 2; });
    std::cout << *it << std::endl;

    int a = 5;
    auto lambda = [&a](int value) { std::cout << "Value: " << a << std::endl; };
    
    int arr[10];
    FillArray(arr);
    for (const auto& item : arr) {
        std::cout << item << ", ";
    }

    return 0;
}
