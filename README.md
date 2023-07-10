# Binary Search Tree (BST)

The `BinarySearchTree.h` header file provides a C++ implementation of a binary search tree (BST). A binary search tree is a type of binary tree in which each node has a value greater than all the values in its left subtree and less than all the values in its right subtree.

## Functionality and Usage

The `BinarySearchTree` class provides the following functionality:

- **Inserting Elements**: Use the `insert` function to add a new element to the binary search tree.

    ```cpp
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    ```

- **Removing Elements**: Use the `remove` function to remove a specified element from the binary search tree.

    ```cpp
    bst.remove(5);
    ```

- **Updating Elements**: Use the `update` function to change the value of an existing element in the binary search tree.

    ```cpp
    bst.update(10, 20);
    ```

- **Clearing the Tree**: Use the `clear` function to remove all elements from the binary search tree, resulting in an empty tree.

    ```cpp
    bst.clear();
    ```

- **Depth-First Search (DFS) Traversal**: Use the `dfs` function to perform a pre-order depth-first search traversal of the binary search tree and print the values of the nodes.

    ```cpp
    bst.dfs();
    ```

- **Breadth-First Search (BFS) Traversal**: Use the `bfs` function to perform a level-order breadth-first search traversal of the binary search tree and print the values of the nodes.

    ```cpp
    bst.bfs();
    ```

- **Searching for a Value**: Use the `search` function to search for a specified value in the binary search tree and return its value if found. If the value is not found, it throws a `std::runtime_error`.

    ```cpp
    int result = bst.search(15);
    ```

- **Working with Class Objects**: The `BinarySearchTree` class can store objects of a custom class if the class defines the necessary operator overloads. To store class objects, ensure that the class defines the following operator overloads:

    - `operator<`: To compare objects and determine their relative order.
    - `operator>`: To compare objects and determine their relative order.
    - `operator==`: To check for equality between objects.

    For example, suppose you have a class `Test` with the following operator overloads:

    ```cpp
    class Test {
    public:
        int age;

        // Operator overloads for comparison
        bool operator<(const Test& other) const {
            return age < other.age; // Compare based on age
        }

        bool operator>(const Test& other) const {
            return age > other.age; // Compare based on age
        }

        bool operator==(const Test& other) const {
            return age == other.age; // Compare based on age
        }
    };
    ```

    You can then use the `BinarySearchTree` class with `Test` objects:

    ```cpp
    BinarySearchTree<Test> bst;
    Test obj1{25};
    Test obj2{30};
    Test obj3{20};

    bst.insert(obj1);
    bst.insert(obj2);
    bst.insert(obj3);
    ```

    If you want to customize the output when printing the objects, you can define the `operator<<` overload as a friend function inside the `Test` class:

    ```cpp
    class Test {
    public:
        int age;

        // Operator overloads for comparison (same as before)

        // Operator overload for output stream
        friend ostream& operator<<(ostream& os, const Test& obj) {
            // Customize the output formatting based on your requirements
            os << "Age: " << obj.age;
            return os;
        }
    };
    ```

    This allows you to print the objects using `cout` or other output streams:

    ```cpp
    Test obj{25};
    cout << obj;  // Output: Age: 25
    ```

## Implementation Details

The `BinarySearchTree` class uses the `BSTNode` class internally to represent each node in the binary search tree. The `BSTNode` class has three members:

- `data`: The value stored in the node.
- `left`: A pointer to the left child node.
- `right`: A pointer to the right child node.

The binary search tree is implemented using recursive functions for operations such as insertion, removal, updating, and searching.

The `dfsTraversal` function performs a pre-order depth-first search traversal of the binary search tree using recursion. The `bfsTraversal` function performs a level-order breadth-first search traversal using a queue.

 ## Credit
 M Talha Khalid @iot noob
 
