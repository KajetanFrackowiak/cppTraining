#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <optional>
#include <string>

std::optional<std::string> ReadFileAsString(const std::string& filepath);

#endif // OPTIONAL_H