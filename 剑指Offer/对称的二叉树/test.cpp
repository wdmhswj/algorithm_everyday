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
    bool checkSymmetricTree(TreeNode* root) {
        if (!root) return true;

        std::function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* left, TreeNode* right) -> bool {
            if (!left && !right) return true;
            else if (!left || !right) return false;
            else if (left->val != right->val) return false;
            else return dfs(left->left, right->right) && dfs(left->right, right->left);
        };
        return dfs(root->left, root->right);
    }
};