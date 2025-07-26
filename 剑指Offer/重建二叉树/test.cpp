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
    TreeNode* deduceTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size()==0) return nullptr;

        std::unordered_map<int, int> map;
        for (int i=0; i<inorder.size(); ++i)
        {
            map[inorder[i]]=i;
        }

        // i表示当前树的根节点在前序序列中的位置，根节点在中序序列的位置为 k=map[preorder[i]]
        // 中序序列中左子树的范围：[j, k-1], 右子树：[k+1, j+n-1]
        // 前序序列中左子树范围：[i+1, i+1+k-1-j]=[i+1, i+k-j]，右子树：[i+k-j+1, i+n-1]
        std::function<TreeNode*(int, int, int)> recursion = [&](int i, int j, int n) -> TreeNode* {
            if (n<1) return nullptr;
            TreeNode* root = new TreeNode(preorder[i]);
            int k = map[preorder[i]];
            root->left = recursion(i+1, j, k-j);
            root->right = recursion(i+k-j+1, k+1, j+n-k-1);
            return root;
        };
        return recursion(0, 0, inorder.size());
    }
};