#include "../../../structs/TreeNode.h"
#include <queue>
// #include <utility>
// #include <vector>
// #include <stack>

// using std::vector;
// using std::stack;
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
    // 递归法
    int maxDepth(TreeNode* root) {
        // 终止条件
        if (root==nullptr) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
    // 层序遍历法
    int maxDepth_1(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        // 辅助队列
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            TreeNode* node = nullptr;
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                if (node->left!=nullptr) {
                    que.push(node->left);
                }
                if (node->right!=nullptr) {
                    que.push(node->right);
                }
            }
            ++depth;
        }
        return depth;
    }
};