#include <iostream>
using namespace std;

// Creating AVL Tree Node
struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
};

// Function to get the height of the tree
int height(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Function to get balance factor
int bal(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Create new node
AVLNode* newNode(int key) {
    AVLNode* node = new AVLNode();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate
AVLNode* rotR(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // new root
}

// Left rotate
AVLNode* rotL(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // new root
}

// Insert with balancing
AVLNode* insert(AVLNode* node, int key) {
    // 1. Normal BST insert
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicates not allowed

    // 2. Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Balance the node
    int b = bal(node);

    // Left Left
    if (b > 1 && key < node->left->key)
        return rotR(node);

    // Right Right
    if (b < -1 && key > node->right->key)
        return rotL(node);

    // Left Right
    if (b > 1 && key > node->left->key) {
        node->left = rotL(node->left);
        return rotR(node);
    }

    // Right Left
    if (b < -1 && key < node->right->key) {
        node->right = rotR(node->right);
        return rotL(node);
    }

    return node; // unchanged if balanced
}

// Preorder traversal
void preOrder(AVLNode* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Post order traversal
void postOrder(AVLNode* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// Inorder traversal
void inOrder(AVLNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    AVLNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of AVL tree: ";
    preOrder(root);
    cout << "\nInorder traversal of AVL tree: ";
    inOrder(root);
    cout << "\nPostorder traversal of AVL tree: ";
    postOrder(root);
    return 0;
}