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
    std::vector<int> decorateRecord(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> ans;
        TreeNode* cur = nullptr;
        while (!q.empty()) {
            for (int i=q.size(); i>0; --i) {
                cur = q.front();
                q.pop();
                ans.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};