#ifndef UNIONS_H
#define UNIONS_H

#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            float i, j, k, l;
        };
        struct {
            float i1, j2;
        };
        struct {
            Vector2 a, b;
        };
    };
};

void PrintVector2(const Vector2& vector);

#endif // UNIONS_H

