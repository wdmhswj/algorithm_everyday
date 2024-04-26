
#include "../../../structs/TreeNode.h"


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
    int countNodes(TreeNode* root) {
        if (root==0) {
            return 0;
        }
        // 判断是不是满二叉树
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth=0, rightDepth=0;
        while (left) {
            leftDepth++;
            left=left->left;
        }
        while (right) {
            rightDepth++;
            right=right->right;
        }
        if (leftDepth==rightDepth) {
            return (2<<leftDepth) - 1;  // 注意优先级
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};