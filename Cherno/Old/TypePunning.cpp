#include "TypePunning.h"
#include <iostream>

struct Entity {
    int x, y;

    int* GetPosition() {
        return &x;
    }
};

int main() {
    Entity e = { 5, 2 };

    // Using TypePunning::PunningCast for type punning
    int* position = TypePunning::PunningCast<int*>(&e);
    int y = TypePunning::PunningCast<int>((char*)&e + sizeof(int));

    std::cout << y << std::endl;
    std::cin.get();
    return 0;
}

