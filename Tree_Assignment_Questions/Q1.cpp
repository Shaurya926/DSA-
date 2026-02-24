// Write a program to check whether a given tree is almost complete binary tree (ACBT) or not.
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isComplete(TreeNode* root) {
    if (!root) return true;
    
    std::queue<TreeNode*> q;
    q.push(root);
    bool foundNull = false;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node->left) {
            if (foundNull) return false;
            q.push(node->left);
        } else {
            foundNull = true;
        }
        
        if (node->right) {
            if (foundNull) return false;
            q.push(node->right);
        } else {
            foundNull = true;
        }
    }
    
    return true;
}
bool isAlmostComplete(TreeNode* root) {
    if (!root) return true;
    
    std::queue<TreeNode*> q;
    q.push(root);
    bool foundNull = false;
    int nullCount = 0;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node->left) {
            if (foundNull) return false;
            q.push(node->left);
        } else {
            foundNull = true;
            nullCount++;
        }
        
        if (node->right) {
            if (foundNull) return false;
            q.push(node->right);
        } else {
            foundNull = true;
            nullCount++;
        }
        
        if (nullCount > 1) return false;
    }
    
    return true;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7); // Uncommenting this will make it a complete binary tree

    if (isAlmostComplete(root)) {
        std::cout << "The tree is an almost complete binary tree." << std::endl;
    } else {
        std::cout << "The tree is not an almost complete binary tree." << std::endl;
    }

    return 0;
}
