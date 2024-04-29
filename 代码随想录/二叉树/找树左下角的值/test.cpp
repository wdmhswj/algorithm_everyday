#include <queue>
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
    int layerTraversal(TreeNode* node) {
        if (node==nullptr) {
            return -1;
        }
        std::queue<TreeNode*>   que;    // 辅助队列
        que.push(node);
        std::vector<int> results;   // 辅助存储可能的结果
        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                if (i==0) {
                    results.push_back(cur->val);
                }
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
        }
            return results.back();

    }

    void preTraversal(TreeNode* node, int depth, int& maxDepth, int& resValue) {
        if (node->left==nullptr && node->right==nullptr) {
            if (depth>maxDepth) {
                maxDepth=depth;
                resValue=node->val;
            }
        }
        if (node->left) {
            preTraversal(node->left, depth+1, maxDepth, resValue);
        }
        if (node->right) {
            preTraversal(node->right, depth+1, maxDepth, resValue);
        }
    }
public:

    // 法1：层序遍历法
    int findBottomLeftValue(TreeNode* root) {
        return layerTraversal(root);
    }

    // 法2：递归法
    int findBottomLeftValue_1(TreeNode* root) {
        int maxDepth = 0;
        int resValue = root->val;
        preTraversal(root, 0, maxDepth, resValue);
        return resValue;
    }
};