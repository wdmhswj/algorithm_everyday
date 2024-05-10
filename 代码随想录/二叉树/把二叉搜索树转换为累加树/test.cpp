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
    void traversal(TreeNode* cur, int& pre) {
        if (cur==nullptr) {
            return;
        }
        traversal(cur->right, pre);
        cur->val+=pre;
        pre = cur->val;
        traversal(cur->left, pre);
    }
    void traversal_1(TreeNode* cur, int& pre) {
        std::stack<TreeNode*> st;
        TreeNode* node = cur;
        while (node!=nullptr || !st.empty()) {
            if (node!=nullptr) {
                st.push(node);
                node = node->right; // 右
            } else {
                node = st.top();    // 中
                st.pop();
                node->val+=pre;
                pre=node->val;
                node=node->left;    // 左
            }
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        traversal(root, pre);
        return root;
    }
};