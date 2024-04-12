#ifndef MULTIPLETYPES_H
#define MULIPLETYPES_H

#include <optional>
#include <string>
#include <filesystem>

enum class ErrorCode {
    None = 0, NotFound = 1, NoAccess = 2
};

std::optional<std::string> ReadFileAsString(const std::string& filepath, ErrorCode& error);

#endif // MULTIPLETYPES_H