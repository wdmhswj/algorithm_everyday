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
    // 递归法
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val<low) {
            return trimBST(root->right, low, high);
        }
        if (root->val>high) {
            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    // 迭代法
    TreeNode* trimBST_1(TreeNode* root, int low, int high) {
        while (root && (root->val<low || root->val>high)) {
            if (root->val<low) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        if (root==nullptr) {
            return nullptr;
        }

        TreeNode* node_l = root;
        TreeNode* node_h = root;
        
        while (node_l && node_l->left) {
            if (node_l->left->val<low) {
                node_l->left = node_l->left->right;
            }
            else {
                node_l = node_l->left;
            }
        }
        while (node_h && node_h->right) {
            if (node_h->right->val>high) {
                node_h->right = node_h->right->left;
            }
            else {
                node_h = node_h->right;
            }
            
        }
        return root;
    }
};