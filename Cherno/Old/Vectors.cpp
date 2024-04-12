#include "Vectors.h"

#include <iostream>

struct vector3 {
    float x, y, z;

    vector3() : x(0), y(0), z(0) {}
    ~vector3() { std::cout << "Destroy" << std::endl; }
    vector3(const float scalar) : x(scalar), y(scalar), z(scalar) {}

    vector3(vector3&& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cout << "Move" << std::endl;
    }

    vector3(const vector3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cout << "Copy" << std::endl;
    }

    vector3& operator=(const vector3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cout << "Copy" << std::endl;
        return *this;
    }

    vector3& operator=(vector3&& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cout << "Move" << std::endl;
        return *this;
    }
};

template <typename T>
void PrintVec(const Vector<T>& vec) {
    for (size_t index = 0; index < vec.Size(); index++) {
        std::cout << vec[index] << std::endl;
    }
}

template <>
void PrintVec(const Vector<vector3>& vec) {
    for (size_t index = 0; index < vec.Size(); index++) {
        std::cout << vec[index].x << " - " << vec[index].y << " - "
                  << vec[index].z << std::endl;
    }
}

int main(int argc, const char* argv[]) {
    // insert code here...
    Vector<vector3> myVec;
    vector3 t(10);
    myVec.PushBack(t);
    myVec.PushBack(vector3());
    myVec.PushBack(vector3(11));
    myVec.PushBack(11);
    PrintVec(myVec);
    myVec.PushBack(vector3());
    PrintVec(myVec);
    return 0;
}