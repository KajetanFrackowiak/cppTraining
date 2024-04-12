#include "MultipleTypes.h"

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <filesystem> // Include <filesystem> for std::filesystem

std::optional<std::string> ReadFileAsString(const std::string& filepath, ErrorCode& error) {
    // Check file existence
    if (!std::filesystem::exists(filepath)) {
        error = ErrorCode::NotFound;
        return {}; // Return an empty optional
    }

    // Check file permissions
    if (!std::filesystem::is_regular_file(filepath)) {
        error = ErrorCode::NoAccess;
        return {}; // Return an empty optional
    }

    std::ifstream stream(filepath);
    if (stream.is_open()) {
        std::string result;
        std::string line;
        while (std::getline(stream, line)) {
            result += line + "\n";
        }
        stream.close();
        return result;
    } else {
        error = ErrorCode::NoAccess;
        return {}; // Return an empty optional
    }
}

int main() {
    ErrorCode error = ErrorCode::None;
    std::optional<std::string> fileData = ReadFileAsString("data.txt", error);
    if (error == ErrorCode::None) {
        if (fileData.has_value()) {
            std::cout << "File read successfully\n";
            std::cout << fileData.value() << std::endl;
        } else {
            std::cout << "Error: ";
            if (error == ErrorCode::NotFound) {
                std::cout << "File not found\n";
            } else if (error == ErrorCode::NoAccess) {
                std::cout << "No access permissions or unable to open file\n";
            }
        }
    } else {
        std::cout << "Error: ";
        if (error == ErrorCode::NotFound) {
            std::cout << "File not found\n";
        } else if (error == ErrorCode::NoAccess) {
            std::cout << "No access permissions or unable to open file\n";
        }
    }

    return 0;
}
