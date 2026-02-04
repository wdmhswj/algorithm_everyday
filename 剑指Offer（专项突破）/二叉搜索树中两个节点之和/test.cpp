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
    bool findTarget(TreeNode* root, int k) {

        std::vector<int> vals;
        std::stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            vals.push_back(root->val);
            root = root->right;
        }

        int index_l = 0;
        int index_r = vals.size()-1;
        int sum = 0;
        while (index_l<index_r) {
            sum = vals[index_l] + vals[index_r];
            if (sum==k) return true;
            else if (sum<k) ++index_l;
            else --index_r;
        }
        return false;
    }

    bool findTarget1(TreeNode* root, int k) {

        std::stack<TreeNode*> left_stk, right_stk;
        TreeNode* left_cur = root, * right_cur = root;

        auto nextLeft = [&]() -> int {
            while (left_cur) {
                left_stk.push(left_cur);
                left_cur = left_cur->left;
            }
            left_cur = left_stk.top(); left_stk.pop();
            int ret = left_cur->val;
            left_cur = left_cur->right;
            return ret;
        };

        auto nextRight = [&]() -> int {
            while (right_cur) {
                right_stk.push(right_cur);
                right_cur = right_cur->right;
            }
            right_cur = right_stk.top(); right_stk.pop();
            int ret = right_cur->val;
            right_cur = right_cur->left;
            return ret;
        };

        int l=nextLeft(), r=nextRight();
        while (l<r) {
            if (l+r==k) return true;
            else if (l+r<k) l=nextLeft();
            else r=nextRight();
        }

        return false;

    }

};