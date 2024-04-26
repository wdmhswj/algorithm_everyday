#include <algorithm>
#include <cstdlib>
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
    int getHeight(TreeNode* node) {
        if (node==nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (leftHeight==-1 || rightHeight==-1 || std::abs(leftHeight-rightHeight)>1) {
            return -1;
        }
        return std::max(leftHeight,rightHeight)+1;
    }
public:

    // 递归法
    bool isBalanced(TreeNode* root) {
        return getHeight(root)>=0;
    }


};
