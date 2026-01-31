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
    int pathSum(TreeNode* root, int targetSum) {
        
        std::unordered_map<long long, int> cnt;
        cnt[0] = 1;
        std::function<int(TreeNode*, long long)> dfs = [&](TreeNode* root, long long s) -> int {
            if (!root) return 0;
            s += root->val;
            int ret = cnt[s-targetSum];
            ++cnt[s];
            ret += dfs(root->left, s) + dfs(root->right, s);
            --cnt[s];
            return ret;
        };

        return dfs(root, 0);
    }
};