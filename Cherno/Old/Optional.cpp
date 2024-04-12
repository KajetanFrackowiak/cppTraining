#include "Optional.h"

#include <fstream>
#include <iostream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        std::string result;
        std::string line;
        while (std::getline(stream, line)) {
            result += line + "\n";
        }
        stream.close();
        return result;
    }

    return std::nullopt;
}

int main() {
    std::optional<std::string> data = ReadFileAsString("data.txt");
    std::string value = data.value_or("Not present");

    std::cout << value << std::endl;
    
    std::optional<int> count;
    int c = count.value_or(100);

    if (data.has_value()) {
        std::cout << "File read successfully\n";
        std::cout << data.value() << std::endl;
    } else {
        std::cout << "File could not be opened\n";
    }

    return 0;
}