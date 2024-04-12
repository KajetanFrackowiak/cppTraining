#include <iostream>

class Random {
public:
    Random(const Random&) = delete;

    static Random& Get() {
        static Random instance;
        return instance;
    }

    static float Float() { return Get().IFloat(); }
private:
    float IFloat() { return m_RandomGenerator; }
    Random() {}

    float m_RandomGenerator = 0.01f;

    static Random s_Instance;

};

namespace RandomClass {
    static float s_RandomGenerator = 0.5f;
    static float Float() { return s_RandomGenerator; }
}

int main() {

    float numberFromNamespace = RandomClass::Float();
    float numberFromClass = Random::Get().Float();
    
    std::cout << numberFromNamespace << std::endl;
    std::cout << numberFromClass << std::endl;

    return 0;
}