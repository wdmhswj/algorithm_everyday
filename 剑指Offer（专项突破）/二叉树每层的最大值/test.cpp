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
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode*> q{{root}};
        std::vector<int> ret;
        while (!q.empty()) {
            int max = INT_MIN;
            for (int i=q.size(); i>0; --i) {
                TreeNode* node = q.front(); q.pop();
                max = std::max(max, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(max);
        }
        return ret;
    }
};