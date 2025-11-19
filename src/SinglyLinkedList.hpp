#pragma once
#include <cstddef>
#include <stdexcept>
#include <initializer_list>

// A simple singly linked list.
template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        explicit Node(const T& v) : value(v), next(nullptr) {}
    };

    Node* head;
    std::size_t _size;

public:
    SinglyLinkedList() : head(nullptr), _size(0) {}

    SinglyLinkedList(std::initializer_list<T> init) : SinglyLinkedList() {
        for (const auto& v : init) {
            push_back(v);
        }
    }

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList(const SinglyLinkedList& other) : SinglyLinkedList() {
        Node* cur = other.head;
        while (cur) {
            push_back(cur->value);
            cur = cur->next;
        }
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if (this != &other) {
            SinglyLinkedList tmp(other);
            swap(tmp);
        }
        return *this;
    }

    void push_front(const T& value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
        ++_size;
    }

    void push_back(const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
        } else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = n;
        }
        ++_size;
    }

    void pop_front() {
        if (!head) {
            throw std::out_of_range("SinglyLinkedList::pop_front on empty");
        }
        Node* old = head;
        head = head->next;
        delete old;
        --_size;
    }

    std::size_t size() const { return _size; }
    bool empty() const { return _size == 0; }

    void clear() {
        while (head) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        _size = 0;
    }

    void swap(SinglyLinkedList& other) {
        std::swap(head, other.head);
        std::swap(_size, other._size);
    }

    // Simple forward iteration
    class Iterator {
    public:
        explicit Iterator(Node* n) : node(n) {}
        T& operator*() { return node->value; }
        Iterator& operator++() { node = node->next; return *this; }
        bool operator!=(const Iterator& other) const { return node != other.node; }
    private:
        Node* node;
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};
