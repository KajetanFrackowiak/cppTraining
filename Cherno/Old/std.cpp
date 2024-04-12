#include <iostream>
#include <string>
#include <algorithm>

namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

namespace apple {
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
}
// using namespace apple;
// using namespace orange;

int main() {
    apple::print("Hello");
    orange::print("Hello");

    return 0;
}