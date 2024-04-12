#include <iostream>
#include <algorithm>

namespace samsung {
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }

    void print_again(const std::string& text) {
        std::cout << "Print V2: " << text << std::endl;
    }
}

namespace apple {

    namespace functions {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
    namespace functions2 {
        void print2(const char* text) {
            std::cout << text << std::endl;
        }
    }
    }
}

int main() {
    using samsung::print_again;
    using samsung::print;
    namespace functions = apple::functions;

    print("Hello");
    print_again("Hello");
    functions::print("Hello");

    return 0;
}