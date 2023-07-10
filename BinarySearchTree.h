#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;
 
    
    BSTNode(T value) { 
        data = value;
        left = nullptr;
        right = nullptr;
    }
    
};

template <typename T>
class BinarySearchTree {
private:
    BSTNode<T>* root;

    BSTNode<T>* insertNode(BSTNode<T>* node, T value) {
        if (node == nullptr) {
            node = new BSTNode<T>(value);
            return node;
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

 

    BSTNode<T>* findMinNode(BSTNode<T>* node) {
        BSTNode<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    BSTNode<T>* removeNode(BSTNode<T>* node, T value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = removeNode(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                BSTNode<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                BSTNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            BSTNode<T>* minNode = findMinNode(node->right);
            node->data = minNode->data;
            node->right = removeNode(node->right, minNode->data);
        }

        return node;
    }

    BSTNode<T>* updateNode(BSTNode<T>* node, T oldValue, T newValue) {
        if (node == nullptr) {
            return node;
        }

        if (oldValue < node->data) {
            node->left = updateNode(node->left, oldValue, newValue);
        }
        else if (oldValue > node->data) {
            node->right = updateNode(node->right, oldValue, newValue);
        }
        else {
            node->data = newValue;
        }

        return node;
    }

    BSTNode<T>* clearNode(BSTNode<T>* node) {
        if (node == nullptr) {
            return nullptr;
        }

        node->left = clearNode(node->left);
        node->right = clearNode(node->right);

        delete node;
        return nullptr;
    }

    void dfsTraversal(BSTNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        dfsTraversal(node->left);
        dfsTraversal(node->right);
    }

    void bfsTraversal(BSTNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::queue<BSTNode<T>*> q;
        q.push(node);

        while (!q.empty()) {
            BSTNode<T>* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
   BSTNode<T>* searchNode(BSTNode<T>* node, const T& value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }
        else {
            return searchNode(node->right, value);
        }
    }
public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(T value) {
        root = insertNode(root, value);
    }

    void remove(T value) {
        root = removeNode(root, value);
    }

    void update(T oldValue, T newValue) {
        root = updateNode(root, oldValue, newValue);
    }

    void clear() {
        root = clearNode(root);
    }

    void dfs() {
        dfsTraversal(root);
    }

    void bfs() {
        bfsTraversal(root);
    }
    
      T search(const T& value) {
        BSTNode<T>* result = searchNode(root, value);
        if (result != nullptr) {
            return result->data;
        }
        else {
            // Handle the case when the value is not found in the tree
            // You can throw an exception or return a default value, depending on your needs
            throw std::runtime_error("Value not found in the tree");
        }
    }
};

#endif