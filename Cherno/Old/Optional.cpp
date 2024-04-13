#include <iostream>
#include <string>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath) {
	std::ifstream stream(filepath);
	if (stream) {
		std::string result;
		// read file
		stream.close();	
		return result;
	}
	
	return {};
}

int main() {	
	std::optional<std::string> data = ReadFileAsString("data.txt");
	if (data.has_value()) {
		std::cout << "File read successfully!\n";
	}
	else {
		data.value();
		std::cout << "File couldn't be opened!\n";
	}
}