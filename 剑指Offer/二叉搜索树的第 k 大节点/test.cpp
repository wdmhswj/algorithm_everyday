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
    int findTargetNode(TreeNode* root, int cnt) {
        int ans = 0;
        std::function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || !cnt) return;
            dfs(root->right);
            if (--cnt == 0) {
                ans = root->val;
            }
            dfs(root->left);
        };
        dfs(root);
        return ans;
    }
};