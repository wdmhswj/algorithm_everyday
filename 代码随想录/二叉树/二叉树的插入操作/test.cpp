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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val<val) {
            root->right = insertIntoBST(root->right, val);
        } else if (root->val>val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }

    TreeNode* insertIntoBST_1(TreeNode* root, int val) {
        if (root==nullptr) {
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        while (cur) {
            if (val<cur->val) {
                if (cur->left==nullptr) {
                    cur->left = new TreeNode(val);
                    break;
                } else {
                    cur = cur->left;
                }
            } else if (val>cur->val) {
                if (cur->right==nullptr) {
                    cur->right = new TreeNode(val);
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};