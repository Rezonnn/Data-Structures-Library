#pragma once
#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

// A simple dynamic array similar to a minimal std::vector.
template <typename T>
class DynamicArray {
public:
    DynamicArray()
        : _size(0), _capacity(0), _data(nullptr) {}

    explicit DynamicArray(std::size_t n, const T& value = T())
        : _size(n), _capacity(n), _data(nullptr) {
        if (_capacity > 0) {
            _data = new T[_capacity];
            std::fill(_data, _data + _size, value);
        }
    }

    DynamicArray(std::initializer_list<T> init)
        : DynamicArray() {
        reserve(init.size());
        for (const auto& v : init) {
            push_back(v);
        }
    }

    DynamicArray(const DynamicArray& other)
        : DynamicArray() {
        reserve(other._size);
        for (std::size_t i = 0; i < other._size; ++i) {
            _data[i] = other._data[i];
        }
        _size = other._size;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            DynamicArray tmp(other);
            swap(tmp);
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] _data;
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            reserve(_capacity == 0 ? 2 : _capacity * 2);
        }
        _data[_size++] = value;
    }

    void pop_back() {
        if (_size == 0) {
            throw std::out_of_range("DynamicArray::pop_back on empty array");
        }
        --_size;
    }

    void reserve(std::size_t new_cap) {
        if (new_cap <= _capacity) return;
        T* new_data = new T[new_cap];
        for (std::size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_cap;
    }

    void clear() {
        _size = 0;
    }

    std::size_t size() const { return _size; }
    std::size_t capacity() const { return _capacity; }
    bool empty() const { return _size == 0; }

    T& operator[](std::size_t i) { return _data[i]; }
    const T& operator[](std::size_t i) const { return _data[i]; }

    T& at(std::size_t i) {
        if (i >= _size) {
            throw std::out_of_range("DynamicArray::at out of range");
        }
        return _data[i];
    }

    const T& at(std::size_t i) const {
        if (i >= _size) {
            throw std::out_of_range("DynamicArray::at out of range");
        }
        return _data[i];
    }

    void swap(DynamicArray& other) {
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
        std::swap(_data, other._data);
    }

private:
    std::size_t _size;
    std::size_t _capacity;
    T* _data;
};
