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
    int calculateDepth(TreeNode* root) {
        int rt = 0;
        std::function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int depth) {
            if (!root) {
                rt = std::max(rt, depth);
                return;
            }
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
        };
        dfs(root, 0);
        return rt;
    }

    int calculateDepth1(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(calculateDepth1(root->left), calculateDepth1(root->right));
    }

    int calculateDepth2(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth=0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++depth;
        }
        return depth;
    }
};