#include "../../utils/utils.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flipTree(TreeNode* root) {
        TreeNode* B = nullptr;
        dfs(root, B);
        return B;
    }

    void dfs(TreeNode* A, TreeNode*& B) {   // 注意 B 的类型为引用
        if (!A) return;
        B = new TreeNode(A->val);
        // std::cout << B->val << " ";
        dfs(A->left, B->right);
        dfs(A->right, B->left);
    }

    TreeNode* flipTree1(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->right = flipTree1(root->left);
        newRoot->left = flipTree1(root->right);
        return newRoot;
    }

    TreeNode* flipTree2(TreeNode* root) {
        if (!root) return root;
        std::swap(root->left, root->right);
        flipTree2(root->left);
        flipTree2(root->right);
        return root;
    }
};


void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // [5,7,9,8,3,2,4]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* flipped = sol.flipTree(root);
    std::cout << "flipped: " << flipped << std::endl;
    // Print the flipped tree
    printTree(flipped);

    flipped = sol.flipTree1(root);
    std::cout << "flipped: " << flipped << std::endl;
    // Print the flipped tree
    printTree(flipped);
    return 0;
}