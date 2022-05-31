#pragma once

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* array;
    size_t size;
public:
    static const size_t BUFF_SIZE;
    Stack() : size{0}, array{new T[BUFF_SIZE]} { }
    void push(const T&);
    T& last() const;
    void pop();
};

template <typename T>
const size_t Stack<T>::BUFF_SIZE {256};

template <typename T>
void Stack<T>::push(const T& val) {
    if(size >= BUFF_SIZE) throw std::out_of_range{"stack overflow"};
    array[size] = val;
    size++;
}

template <typename T>
T& Stack<T>::last() const {
    if(size == 0) throw std::out_of_range{"stack is empty"};
    return array[size-1];
}

template <typename T>
void Stack<T>::pop() {
    if(size == 0) throw std::out_of_range{"stack is empty"};
    size--;
}