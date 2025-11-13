#include <iostream>
#include "DynamicArray.hpp"
#include "SinglyLinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "BinarySearchTree.hpp"

// Demo program showcasing custom data structures.

int main() {
    std::cout << "==============================\n";
    std::cout << " C++ Data Structures Library\n";
    std::cout << "==============================\n\n";

    // 1. DynamicArray demo
    std::cout << "[1] DynamicArray<int>\n";
    DynamicArray<int> arr;
    for (int i = 1; i <= 5; ++i) {
        arr.push_back(i * 10);
    }
    std::cout << "Contents: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nSize: " << arr.size() << ", Capacity: " << arr.capacity() << "\n\n";

    // 2. SinglyLinkedList demo
    std::cout << "[2] SinglyLinkedList<std::string>\n";
    SinglyLinkedList<std::string> list;
    list.push_back("alpha");
    list.push_back("beta");
    list.push_front("start");
    std::cout << "Contents: ";
    for (auto& s : list) {
        std::cout << s << " ";
    }
    std::cout << "\nSize: " << list.size() << "\n\n";

    // 3. Stack demo
    std::cout << "[3] Stack<int>\n";
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << "Top element: " << st.top() << "\n";
    st.pop();
    std::cout << "Top after pop: " << st.top() << ", size: " << st.size() << "\n\n";

    // 4. Queue demo
    std::cout << "[4] Queue<int>\n";
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << "Front element: " << q.front() << "\n";
    q.pop();
    std::cout << "Front after pop: " << q.front() << ", size: " << q.size() << "\n\n";

    // 5. BinarySearchTree demo
    std::cout << "[5] BinarySearchTree<int>\n";
    BinarySearchTree<int> bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);

    std::cout << "Inorder traversal (sorted): ";
    bst.inorder_print();
    std::cout << "Contains 6? " << (bst.contains(6) ? "Yes" : "No") << "\n";
    std::cout << "Min: " << (bst.min().has_value() ? std::to_string(bst.min().value()) : "N/A") << "\n";
    std::cout << "Max: " << (bst.max().has_value() ? std::to_string(bst.max().value()) : "N/A") << "\n";

    std::cout << "\nDone.\n";
    return 0;
}
