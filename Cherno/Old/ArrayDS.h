#ifndef ARRAYDS_H
#define ARRAYDS_H

#include <array>
#include <iostream>
#include <string>

template <typename Array>
class ArrayIterator {
   public:
    using ValueType = typename Array::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

   private:
    PointerType m_Ptr;

   public:
    ArrayIterator(PointerType ptr) : m_Ptr(ptr) {}
    ArrayIterator& operator++() {
        m_Ptr++;
        return *this;
    }
    ArrayIterator operator++(int) {
        ArrayIterator iterator = *this;
        ++(*this);
        return iterator;
    }
    ArrayIterator& operator--() {
        m_Ptr--;
        return *this;
    }
    ArrayIterator operator--(int) {
        ArrayIterator iterator = *this;
        --(*this);
        return iterator;
    }
    ReferenceType operator[](int index) { return *(m_Ptr + index); }
    PointerType operator->() { return m_Ptr; }
    ReferenceType operator*() { return *m_Ptr; }
    bool operator==(const ArrayIterator& other) const {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const ArrayIterator& other) const {
        return !(m_Ptr == other.m_Ptr);
    }
    // *this reference to the object
};

template <typename T, size_t S>
class Array {
   public:
    using ValueType = T;
    using PointerType = T*;
    using ReferenceType = T&;
    using Iterator = ArrayIterator<Array<T, S>>;

    Array(std::initializer_list<T> initList) {
        std::copy(initList.begin(), initList.end(), m_Data);
    }
    constexpr size_t Size() { return S; }
    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }
    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }

    // To for-each

    Iterator begin() { return Iterator(m_Data); }
    Iterator end() { return Iterator(m_Data + m_Size); }

   private:
    T m_Data[S];
    size_t m_Size = S;
};

#endif  // ARRAYDS