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
    int sumNumbers(TreeNode* root) {
        if (root==nullptr) return 0;
        int sum = 0;
        std::string str;
        str += '0'+root->val;
        _sumNumbers(root, sum, str);
        return sum;
    }

    int sumNumbers1(TreeNode* root) {
        int ret = 0;
        _sumNumbers1(root, ret, 0);
        return ret;
    }

    int sumNumbers1(TreeNode* root) {
        return _sumNumbers2(root, 0);
    }

private:
    void _sumNumbers(TreeNode* root, int& sum, std::string& str) {
        // 叶子节点
        if (root->left==nullptr && root->right==nullptr) {
            sum += std::stoi(str);
            return;
        }

        if (root->left) {
            str += '0'+root->left->val;
            _sumNumbers(root->left, sum, str);
            str.pop_back();
        }
        
        
        if (root->right) {
            str += '0'+root->right->val;
            _sumNumbers(root->right, sum, str);
            str.pop_back();
        }
        
    }

    void _sumNumbers1(TreeNode* root, int& sum, int presum) {
        // 空节点
        if (!root) return;

        presum = presum*10 + root->val;

        // 叶子节点
        if (root->left==nullptr && root->right==nullptr) {
            sum += presum;
            return;
        }
        _sumNumbers1(root->left, sum, presum);
        _sumNumbers1(root->right, sum, presum);
        
    }

    int _sumNumbers2(TreeNode* root, int presum) {
        if (!root) return 0; // 处理非叶子节点的空子节点的场景
        int sum = presum*10 + root->val;
        if (root->left==nullptr && root->right==nullptr)
            return sum; // 当前路径数字之和
        return _sumNumbers2(root->left, sum) + _sumNumbers2(root->right, sum);
        
    }


};