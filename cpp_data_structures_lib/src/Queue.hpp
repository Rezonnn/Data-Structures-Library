#pragma once
#include <cstddef>
#include <stdexcept>

// A simple FIFO queue using a singly linked list internally.
template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;
        explicit Node(const T& v) : value(v), next(nullptr) {}
    };

    Node* front_;
    Node* back_;
    std::size_t _size;

public:
    Queue() : front_(nullptr), back_(nullptr), _size(0) {}

    ~Queue() {
        clear();
    }

    void push(const T& value) {
        Node* n = new Node(value);
        if (!back_) {
            front_ = back_ = n;
        } else {
            back_->next = n;
            back_ = n;
        }
        ++_size;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue::pop on empty queue");
        }
        Node* old = front_;
        front_ = front_->next;
        if (!front_) {
            back_ = nullptr;
        }
        delete old;
        --_size;
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue::front on empty queue");
        }
        return front_->value;
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue::front on empty queue");
        }
        return front_->value;
    }

    bool empty() const { return _size == 0; }
    std::size_t size() const { return _size; }

    void clear() {
        while (front_) {
            Node* temp = front_->next;
            delete front_;
            front_ = temp;
        }
        back_ = nullptr;
        _size = 0;
    }
};
