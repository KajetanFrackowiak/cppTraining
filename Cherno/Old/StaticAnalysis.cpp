#include <iostream>

struct Entity {
};

Entity* LoadEntity() {
	return nullptr;
}

int main() {
	Entity* entity = LoadEntity();


	const char* string = "Hello";
	char* buffer = new char[strlen(string)];
	memcpy(buffer, string, strlen(string));
	
	

	uint32_t width = 800, height = 600;
	uint32_t* buffer = new uint32_t[width * height];
	
	for (uint32_t y = 0; y < height; y++) {
		for (uint32_t x = 0; x < width; x++) {
			buffer[x + y * width] = 0;
		}
	}
	return 0;
}