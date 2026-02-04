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
    TreeNode* convertBST(TreeNode* root) {
        std::stack<TreeNode*> stk;
        TreeNode* cur = root;
        int right_sum = 0;
        while (cur!=nullptr || !stk.empty()) {
            while (cur!=nullptr) {
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top(); stk.pop();

            right_sum += cur->val;
            cur->val = right_sum;

            cur = cur->left;
        }
        return root;
    }
};