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
private:
    bool isLeafNode(TreeNode* node) {
        return node->left==nullptr && node->right==nullptr;
    }
    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left!=nullptr) {  // 左子树不为空
            // 左孩子是否为叶子节点，若是则直接加，若不是，则加递归调用后的结果
            ans += isLeafNode(node->left)?node->left->val:dfs(node->left);
        }
        if (node->right!=nullptr && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return root!=nullptr ? dfs(root) : 0;
    }
    int sumOfLeftLeaves_1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (node->left) {
                if (isLeafNode(node->left)) {
                    ans += node->left->val;
                } else {
                    que.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {
                    que.push(node->right);
                }
            }
        }
        return ans;
    }

    int dfs_1(TreeNode* node, bool isLeft) {
        
        if (!node) {
            return 0;
        }
        if (node->left==nullptr && node->right==nullptr && isLeft) {
            return node->val;
        }

        return dfs_1(node->left, true) + dfs_1(node->right, false);
        

    }
    int sumOfLeftLeaves_2(TreeNode* root) {
        return dfs_1(root, false);
    }
};