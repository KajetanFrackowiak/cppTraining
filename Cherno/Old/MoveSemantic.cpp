//#include <iostream>
//
//class String {
//public:
//	String() = default;
//
//	String(const char* string) {
//		printf("Created!\n");
//		m_Size = strlen(string);
//		m_Data = new char[m_Size];
//		memcpy(m_Data, string, m_Size);
//	}
//	String(const String& other) {
//		printf("Copied!\n");
//		m_Size = other.m_Size;
//		m_Data = new char[m_Size];
//		memcpy(m_Data, other.m_Data, m_Size);
//	}
//
//	String(String&& other) noexcept {
//		printf("Moved\n");
//		m_Size = other.m_Size;
//		m_Data = other.m_Data;
//	
//		other.m_Size = 0;
//		other.m_Data = nullptr;
//	}
//	~String() {
//		printf("Destroyed!\n");
//		delete m_Data;
//	}
//
//	void Print() {
//		for (uint32_t i = 0; i < m_Size; i++) {
//			printf("%c", m_Data[i]);
//		}
//		printf("\n");
//	}
//
//private:
//	char* m_Data;
//	uint32_t m_Size;
//
//};
//
//class Entity {
//public:
//	Entity(const String& name) : m_Name(name) {}
//	
//	Entity(String&& name) : m_Name((String&&)name) {}
//
//	void PrintName() {
//		m_Name.Print();
//	}
//private:
//	String m_Name;
//};
//
//int main() {
//	Entity entity(String("Cherno"));
//	entity.PrintName();
//
//	return 0;
//}


#include <iostream>

class MyObject {
public:
    MyObject(int size) : m_Size(size), m_Data(new int[size]) {
        std::cout << "Constructor: Allocated memory of size " << m_Size << std::endl;
    }

    // Move constructor
    MyObject(MyObject&& other) noexcept : m_Size(other.m_Size), m_Data(other.m_Data) {
        std::cout << "Move Constructor: Moving resources" << std::endl;
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~MyObject() {
        delete[] m_Data;
        std::cout << "Destructor: Deallocated memory" << std::endl;
    }
    
private:
    int m_Size;
    int* m_Data;
};

int main() {
    MyObject obj1(5); // Create a MyObject with dynamic memory allocation
    MyObject obj2(std::move(obj1)); // Move obj1 into obj2
    
    
    return 0;
}
