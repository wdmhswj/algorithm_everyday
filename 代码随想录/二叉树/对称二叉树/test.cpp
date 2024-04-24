#include "../../../structs/TreeNode.h"
#include <queue>
#include <utility>
#include <vector>
#include <stack>

// using std::vector;
using std::stack;
using std::queue;

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
    // 迭代法：每次处理2个对称的节点
    bool isSymmetric_1(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }
        queue<TreeNode*> que;   // 辅助队列
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();

            // 都为空
            if (left==nullptr && right==nullptr) {
                continue;
            }else if (left==nullptr || right==nullptr || left->val!=right->val) {
                return false;
            }

            que.push(left->left); // 左左
            que.push(right->right); // 右右 

            que.push(left->right);  // 左右
            que.push(right->left);  // 右左
        }
        return true;
    }

    // 递归
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }
        return helper(root->left, root->right);

    }
    bool helper(TreeNode* left, TreeNode* right){
        if (left==nullptr&&right==nullptr) {
            return true;
        }
        if (left!=nullptr&&right==nullptr) {
            return false;
        }
        if (left==nullptr&&right!=nullptr) {
            return false;
        }
        return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
    }
};