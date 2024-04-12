#include <iostream>
#include <array>
#include <random>
#include <vector>

template <std::size_t Size>
void PrintArray(const std::array<int, Size>& data) {
    for (int el : data) {
        std::cout << el << std::endl;
    }
}

template <std::size_t Size>
void FillArray(std::array<int, Size>& data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < Size; i++) {
        data[i] = distribution(gen);
    }
}

void HelloWord(int a) {
    std::cout << "Hello, World! " << a << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values)
        func(value);
}

void PrintValue(int value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    // std::array<int, 5> data;
    // FillArray(data);
    // PrintArray(data);

    // typedef void(*HelloWorldFunction)(int);
    // HelloWorldFunction function = HelloWord; 
    // function(8);

    std::vector<int> values = { 1, 2, 3, 4, 5 };
    // ForEach(values, PrintValue);

    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
    
    return 0;
}
