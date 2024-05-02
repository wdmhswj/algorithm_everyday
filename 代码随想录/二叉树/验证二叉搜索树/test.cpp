#include <climits>
#include <queue>
#include <stack>
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
    int getMax(TreeNode* root) {
        std::queue<TreeNode*> que;  // 辅助队列
        que.push(root);
        int max = root->val;
        while (!que.empty()) {
            int size = que.size();
            TreeNode* node = nullptr;
            for (int i=0; i<size; i++) {
                node = que.front();
                que.pop();
                if (node->val>max) {
                    max = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return max;
    }
     int getMin(TreeNode* root) {
        std::queue<TreeNode*> que;  // 辅助队列
        que.push(root);
        int min = root->val;
        while (!que.empty()) {
            int size = que.size();
            TreeNode* node = nullptr;
            for (int i=0; i<size; i++) {
                node = que.front();
                que.pop();
                if (node->val<min) {
                    min = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return min;
    }

    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root==nullptr) {
            return true;
        }
        if (root->val<=lower || root->val>=upper) {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
public:
    // 法1：暴力求最大、最小
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }
        if (root->left) {
            if (!(getMax(root->left)<root->val)) {
                return false;
            }
        }
        if (root->right) {
            if (!(getMin(root->right)>root->val)) {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }

    // 法2：递归法优化
    bool isValidBST_1(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    // 法3：中序遍历
    bool isValidBST_2(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }
        std::stack<TreeNode*> st;   // 辅助栈
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur!=nullptr || !st.empty()) {
            if (cur!=nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre!=nullptr && cur->val<=pre->val) {
                    return false;
                }
                pre = cur;  // 更新pre
                cur = cur->right;
            }
        }
        return true;
    }
};