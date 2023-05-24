#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include "sort.hpp"
#include <iostream>

template<typename T>
struct Array {
private:
    int m_size = 0;
    T* m_arr = nullptr;

public:
    Array(int size = 0);
    Array(const Array& srcArr);
    Array& operator=(const Array& srcArr);
    ~Array();
    void deepCopy(const Array& srcArr);
    void read(std::istream& in, std::ostream& out);
    void print(std::ostream& out) const;

    T& operator[](int index);
    const T& operator[](int index) const;

    // hack nao
    // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Array<U>& arr); 
    friend std::istream& operator>>(std::istream& in, Array& arr) = delete;
    void sort(cmpFcnPtr<T> cmpFcn);
};

template<typename T>
Array<T>::Array(int size): m_size(size) {
    if (size <= 0) {
        m_arr = nullptr;
    } else {
        m_arr = new T[size];
    }
}

template<typename T>
Array<T>::Array(const Array<T>& srcArr) {
    deepCopy(srcArr);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& source) {
    // self-reference check
    if (this == &source) {
        return this;
    }

    deepCopy(source);
}

template<typename T>
Array<T>::~Array() {
    delete[] m_arr;
}

template<typename T>
void Array<T>::deepCopy(const Array<T>& source) {
    delete[] m_arr;

    this->m_size = source.m_size;
    
    if (source.m_arr) {
        this->m_arr = new T[this->m_size];
        for (int i = 0; i < this->m_size; ++i) {
            this->m_arr[i] = source.m_arr[i];
        }
    } else {
        this->m_arr = nullptr;
    }
}

template<typename T>
void Array<T>::read(std::istream& in, std::ostream& out) {
    out << "Input current array:\n";
    out << "Please input the size of array: ";
    in >> this->m_size;
    if (this->m_size > 0) {
        this->m_arr = new T[this->m_size];
    } else {
        this->m_size = 0;
    }
    if (this->m_size) {
        out << "Please input the elements of current array:\n";
        for (int i = 0; i < m_size; ++i) {
            out << "Input a[" << i << "] = ";
            in >> m_arr[i];
        }
    }
}

template<typename T>
void Array<T>::print(std::ostream& out) const {
    out << *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    out << "Current array:\n";
    out << "size = " << arr.m_size << '\n';
    out << "List of element in array:\n";
    for (int i = 0; i < arr.m_size; ++i) {
        out << "arr[" << i << "] = " << arr[i] << '\n';
    }
    out.put('\n');
    return out;
}

template<typename T>
void Array<T>::sort(cmpFcnPtr<T> cmpFcn) {
    ::sort(m_arr, m_size, cmpFcn);
}

template<typename T>
T& Array<T>::operator[](int index) {
    return m_arr[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    return m_arr[index];
}

// template<typename T>
// std::istream& operator>>(std::istream& in, Array<T>& arr) {
    
// }

#endif