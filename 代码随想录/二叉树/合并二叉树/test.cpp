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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 如果有树为空，则返回另一个树
        if (root1==nullptr) {
            return root2;
        }
        if (root2==nullptr) {
            return root1;
        }
        
        // 直接修改左树节点作为新的节点
        root1->val+=root2->val;
        // 递归对左右子树处理
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right= mergeTrees(root1->right, root2->right);
        return root1;
    }
};