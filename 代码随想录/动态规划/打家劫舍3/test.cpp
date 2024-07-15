#include <algorithm>
#include <cstddef>
#include <unordered_map>
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
    std::unordered_map<TreeNode*, int> map;
public:
    int rob(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        if (map.find(root)!=map.end()) {
            return map[root];
        }
        int ret=0;
        if (root->left && root->right) {
            ret=std::max(root->val+rob(root->left->left)+rob(root->left->right)
            +rob(root->right->left)+rob(root->right->right), rob(root->left)+rob(root->right));
        } else if (root->left) {
            ret=std::max(root->val+rob(root->left->left)+rob(root->left->right), rob(root->left));
        }else if (root->right) {
            ret=std::max(root->val+rob(root->right->left)+rob(root->right->right), rob(root->right));
        }else{
            ret=root->val;
        }
        map[root]=ret;
        return ret;
    }

    int rob1(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        auto vec=robTree(root);
        return std::max(vec[0], vec[1]);
    }

    std::vector<int> robTree(TreeNode* root) {
        if (root==nullptr) {
            return {0, 0};
        }
        auto left = robTree(root->left);
        auto right = robTree(root->right);
        int value1=root->val+left[0]+right[0];
        int value2=std::max(left[0], left[1])+std::max(right[0], right[1]);
        return {value2, value1};
    }
};