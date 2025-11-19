#pragma once
#include <iostream>
#include <optional>

// A simple binary search tree (BST) supporting insert, search, inorder traversal, and min/max.
template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        explicit Node(const T& k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(const T& key) {
        root = insert_node(root, key);
    }

    bool contains(const T& key) const {
        Node* cur = root;
        while (cur) {
            if (key < cur->key) cur = cur->left;
            else if (cur->key < key) cur = cur->right;
            else return true;
        }
        return false;
    }

    std::optional<T> min() const {
        if (!root) return std::nullopt;
        Node* cur = root;
        while (cur->left) cur = cur->left;
        return cur->key;
    }

    std::optional<T> max() const {
        if (!root) return std::nullopt;
        Node* cur = root;
        while (cur->right) cur = cur->right;
        return cur->key;
    }

    void inorder_print() const {
        inorder(root);
        std::cout << "\n";
    }

private:
    static Node* insert_node(Node* node, const T& key) {
        if (!node) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert_node(node->left, key);
        } else if (node->key < key) {
            node->right = insert_node(node->right, key);
        }
        // if equal, do nothing (no duplicates)
        return node;
    }

    static void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

    static void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};
