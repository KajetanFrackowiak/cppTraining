#include <iostream>
#include <string>
#include <cstdint>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size) {
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

#define STRING_VIEW 0
#if STRING_VIEW
void PrintName(const std::string_view name) {
    std::cout << name << std::endl;
}
#else
void PrintName(const std::string& name) {
    std::cout << name << std::endl;
}
#endif

int main() {
    std::string name = "Kajetan Frackowiak";

#if STRING_VIEW
    std::string_view firstName(name.c_str(), 7);
    std::string_view lastName(name.c_str() + 8);
#else
    std::string firstName = name.substr(0, 7);
    std::string lastName = name.substr(8);
#endif

    PrintName(firstName);
    PrintName(lastName);
    std::cout << s_AllocCount << " allocations" << std::endl;
    return 0;
}