#include <iostream>
#include <array>

template<typename T, size_t S>
class Array {
public:
	constexpr int Size() const { return S;  }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; } // Dodajemy const    
    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }

    // begin() and end()
    T* begin() { return m_Data;  }
    const T* begin() const { return m_Data; }
    T* end() { return m_Data + S; }
    const T* end() const { return m_Data + S; }
private:
	T m_Data[S];	
};

int main() {
    Array<int, 5> data;

    const auto& arrRef = data;
    //static_assert(data.Size() < 10, "Size is too large");    
    
    memset(&data[0], 0, data.Size() * sizeof(int)); // Set all integer insight to be 0

    for (size_t i = 0; i < arrRef.Size(); i++) {
        //std::cout << arrRef[i] << std::endl;
        //data[i] = 10;
        std::cout << data[i] << std::endl;
    }

    Array<std::string, 2> data1;
    data1[0] = "Manchester";
    data1[1] = "United";
    
    for (auto& element : data1) {
        std::cout << element << std::endl;
    }

    return 0;
}