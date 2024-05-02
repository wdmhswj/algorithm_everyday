#include <climits>
#include <vector>
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
private:
    void helper(TreeNode* root, int& min) {
        if (root==nullptr) {
            return;
        }
        TreeNode* left = root->left;
        while (left) {
            if (left->right==nullptr) {
                break;
            }
            left = left->right;
        }
        TreeNode* right = root->right;
        while (right) {
            if (right->left==nullptr) {
                break;
            }
            right = right->left;
        }
        int leftDiff = INT_MAX, rightDiff = INT_MAX;
        if (left) {
            leftDiff = root->val-left->val;
        }
        if (right) {
            rightDiff = right->val-root->val;
        }
        min = (min>leftDiff)?leftDiff:min;
        min = (min>rightDiff)?rightDiff:min;
        helper(root->left, min);
        helper(root->right, min);
    }

    void traversal(TreeNode* root, std::vector<int>& ascend) {
        if (root==nullptr) {
            return;
        }
        traversal(root->left, ascend);
        ascend.emplace_back(root->val);
        traversal(root->right, ascend);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        helper(root, res);
        return res;
    }

    int getMinimumDifference_1(TreeNode* root) {
        std::vector<int> ascend;
        traversal(root, ascend);
        int res = INT_MAX;
        for (int i=0; i<ascend.size()-1; i++) {
            int diff = ascend[i+1]-ascend[i];
            if (diff<res) {
                res =diff;
            }
        }
        return res;
    }
};