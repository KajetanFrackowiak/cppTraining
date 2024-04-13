#include "Unions.h"
#include <iostream>

void PrintVector2(const Vector2& vector) {
    std::cout << "(" << vector.x << " " << vector.y << ")" << std::endl;
}
int main() {
    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    PrintVector2(vector.a);
    PrintVector2(vector.b);

    vector.z = 500.0f;
    vector.j = 200.0f;
    vector.i1 = 700.0f;

    std::cout << "-------------------" << std::endl;

    PrintVector2(vector.a);
    PrintVector2(vector.b);

    std::cin.get();
}
