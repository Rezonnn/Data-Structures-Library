# 📚 C++ Data Structures Library

My **C++17 data structures project** that showcases:

- Custom containers
- Templates
- Pointers and dynamic memory
- Basic algorithms and traversal

It includes:

- `DynamicArray<T>` – a minimal `std::vector`-like dynamic array
- `SinglyLinkedList<T>` – singly linked list with push_front / push_back and iteration
- `Stack<T>` – LIFO stack using `DynamicArray`
- `Queue<T>` – FIFO queue using a linked-list-style internal representation
- `BinarySearchTree<T>` – classic BST with insert, search, inorder traversal, min, max

---

## 🧠 Implemented Data Structures

### 1. `DynamicArray<T>`
- Backed by a raw `T*` and manual `new[]` / `delete[]`
- Methods:
  - `push_back`, `pop_back`
  - `reserve`
  - `size`, `capacity`, `empty`
  - `operator[]`, `at`

### 2. `SinglyLinkedList<T>`
- Node-based structure: `value` + `next` pointer
- Methods:
  - `push_front`, `push_back`, `pop_front`
  - `size`, `empty`, `clear`
  - Basic forward iterator (`begin()`, `end()`)

### 3. `Stack<T>`
- Built on top of `DynamicArray<T>`
- Methods:
  - `push`, `pop`, `top`
  - `size`, `empty`

### 4. `Queue<T>`
- Internally uses a small singly linked list with:
  - `front_`, `back_` pointers
- Methods:
  - `push`, `pop`, `front`
  - `size`, `empty`, `clear`

### 5. `BinarySearchTree<T>`
- Classic BST (no balancing)
- Methods:
  - `insert`
  - `contains`
  - `min`, `max` (return `std::optional<T>`)
  - `inorder_print` for sorted output

---

## ▶️ Build & Run

### Option 1 – Using CMake (Recommended)

From inside the project folder:

```bash
mkdir build
cd build
cmake ..
cmake --build .
./data_structures_demo       # On Windows: data_structures_demo.exe
```

### Option 2 – Using g++ directly

From the project root:

```bash
g++ -std=c++17 -O2 -Isrc src/main.cpp -o data_structures_demo
./data_structures_demo       # On Windows: data_structures_demo.exe
```

---

## 🧪 What the Demo Does

`main.cpp` demonstrates each data structure:

- Builds a `DynamicArray<int>` and prints its contents, size, and capacity
- Creates a `SinglyLinkedList<std::string>` and iterates over it
- Uses a `Stack<int>` to show LIFO behavior
- Uses a `Queue<int>` to show FIFO behavior
- Builds a `BinarySearchTree<int>`, inserts values, and:
  - Prints inorder traversal (sorted)
  - Checks membership with `contains`
  - Prints `min` and `max`

You can run it and see the outputs directly in the console.

---

## 📂 Project Structure

```text
cpp_data_structures_lib/
├─ src/
│  ├─ DynamicArray.hpp
│  ├─ SinglyLinkedList.hpp
│  ├─ Stack.hpp
│  ├─ Queue.hpp
│  ├─ BinarySearchTree.hpp
│  └─ main.cpp
├─ CMakeLists.txt
└─ README.md
```
