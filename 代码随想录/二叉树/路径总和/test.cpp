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
private:
    bool preTraversal(TreeNode* node, int curSum, int targetSum) {
        curSum += node->val;
        if (node->left==nullptr && node->right==nullptr) {
            if (curSum==targetSum) {
                return true;
            }
            return false;
        }else if (node->left!=nullptr && node->right==nullptr) {
            return preTraversal(node->left, curSum, targetSum);
        }else if (node->right!=nullptr && node->left==nullptr) {
            return preTraversal(node->right, curSum, targetSum);
        }else {
            return preTraversal(node->left, curSum, targetSum) || preTraversal(node->right, curSum, targetSum);
        }
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) {
            return false;
        }
        return preTraversal(root, 0, targetSum);
    }
};