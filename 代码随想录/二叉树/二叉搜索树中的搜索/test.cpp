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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val==val) {
            return root;
        } else if (val<root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }

    TreeNode* searchBST_1(TreeNode* root, int val) {
        if (root==nullptr) {
            return nullptr;
        }
        TreeNode* res = root;
        while (res!=nullptr) {
            if (res->val==val) {
                break;
            } else if (res->val<val) {
                res = res->right;
            } else {
                res = res->left;
            }
        }
        return res;
    }
};