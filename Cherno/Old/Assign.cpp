#include <iostream>
#include <sstream>
#include <vector>

class HashTable {
public:
    struct Entry {
        std::string Data;
        bool isDeleted = false;
    };
    static const int Size = 26;
public:
    HashTable() = default;

    void Add(const std::string& entryName) {
        int index = GetIndex(entryName);
        while (!m_Entries[index].Data.empty() && !m_Entries[index].isDeleted) {
            index = (index + 1) % Size;
        }
        m_Entries[index].Data = entryName;
        m_Entries[index].isDeleted = false;
    }

    void Delete(const std::string& entryName) {
        int index = GetIndex(entryName);
        while (m_Entries[index].Data != entryName && !m_Entries[index].Data.empty()) {
            index = (index + 1) % Size;
        }
        if (m_Entries[index].Data == entryName) {
            m_Entries[index].isDeleted = true;
        }
    }

    void Print() {
        for (auto& m_Entry : m_Entries) {
            if (!m_Entry.Data.empty() && !m_Entry.isDeleted) {
                std::cout << m_Entry.Data << std::endl;
            }
        }
    }

private:
    static int GetIndex(const std::string& entryString) {
        return entryString[0] - 'A';
    }

private:
    Entry m_Entries[Size];
};

int main() {
    std::string input;
    std::cout << "Write your input: "; // Aapple Aorange Agrape Dapple Astrawberry
    std::getline(std::cin, input);

    HashTable hashTable;

    std::stringstream ss(input);

    while (ss.good()) {
        std::string token;
        ss >> token;

        std::string entryName = token.substr(1);
        if (token[0] == 'A') {
            hashTable.Add(entryName);
        } else if (token[0] == 'D') {
            hashTable.Delete(entryName);
        }
    }

    hashTable.Print();

    return 0;
}
