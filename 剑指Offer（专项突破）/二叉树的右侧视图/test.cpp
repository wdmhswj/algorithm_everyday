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
    std::vector<int> rightSideView(TreeNode* root) {
        if (root==nullptr) return {};

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> ret;
        int num = 0;
        TreeNode* node = nullptr;
        while (!q.empty()) {
            ret.push_back(q.back()->val);
            num = q.size();
            for (int i=0; i<num; ++i)
            {
                node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            }
        }
        return ret;
    }
};