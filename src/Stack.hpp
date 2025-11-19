#pragma once
#include <stdexcept>
#include "DynamicArray.hpp"

// A basic LIFO stack built on top of DynamicArray.
template <typename T>
class Stack {
public:
    Stack() = default;

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack::pop on empty stack");
        }
        data.pop_back();
    }

    T& top() {
        if (empty()) {
            throw std::out_of_range("Stack::top on empty stack");
        }
        return data[data.size() - 1];
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack::top on empty stack");
        }
        return data[data.size() - 1];
    }

    bool empty() const { return data.size() == 0; }
    std::size_t size() const { return data.size(); }

private:
    DynamicArray<T> data;
};
