#include "Any.h"


std::string getTypeName(const std::type_info& info) {
    std::string name = info.name();
    return name;
}

int main() {
    std::vector<std::any> vec;
    vec.push_back(42);
    vec.push_back(3.14);
    vec.push_back(std::string("Hello"));
    vec.push_back(std::byte(0x0F));
    vec.push_back(true);

    for (const auto& elem: vec) {
        if (elem.type() == typeid(int))
            std::cout << "Type: " << getTypeName(elem.type()) << " Value: " << std::any_cast<int>(elem) << std::endl;
        else if (elem.type() == typeid(double))
            std::cout << "Type: " << getTypeName(elem.type()) << " Value: " << std::any_cast<double>(elem) << std::endl;
        else if (elem.type() == typeid(std::string)) 
            std::cout << std::any_cast<std::string>(elem) << std::endl;
        else if (elem.type() == typeid(std::byte))
            std::cout << std::to_integer<int>(std::any_cast<std::byte>(elem)) << std::endl;
        else
            std::cout << "Unknown type" << std::endl;
    }

    return 0;
}