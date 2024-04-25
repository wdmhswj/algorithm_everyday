#include <algorithm>
#include <queue>
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
public:
    int minDepth(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        if (root->left==nullptr && root->right!=nullptr) {
            return 1+minDepth(root->right);
        }
        if (root->left!=nullptr && root->right==nullptr) {
            return 1+minDepth(root->left);
        }
        return 1+std::min(minDepth(root->left), minDepth(root->right));
    }

    int minDepth_1(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        // 辅助队列
        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            ++depth;
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left==nullptr && node->right==nullptr) {
                    return depth;
                }
                if (node->left!=nullptr) {
                    que.push(node->left);
                }
                if (node->right!=nullptr) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};