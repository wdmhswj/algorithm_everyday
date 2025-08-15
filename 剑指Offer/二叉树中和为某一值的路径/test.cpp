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
    std::vector<std::vector<int>> pathTarget(TreeNode* root, int target) {

        std::vector<std::vector<int>> rt;
        std::vector<int> tmp;
        std::function<void(int sum, TreeNode*)> dfs = [&](int sum, TreeNode* root) {
            if (!root) return;
            tmp.push_back(root->val);
            sum += root->val;
            if (!root->left && !root->right && sum==target) {
                rt.push_back(tmp);
            } else {
                if (root->left) dfs(sum, root->left);
                if (root->right) dfs(sum, root->right);
            }
            tmp.pop_back();   
        };

        dfs(0, root);
        return rt;
    }
};