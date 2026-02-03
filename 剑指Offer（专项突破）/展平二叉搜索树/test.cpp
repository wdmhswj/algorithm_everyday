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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        dfs(root, left, right);
        return left;
    }

    TreeNode* increasingBST1(TreeNode* root) {
        std::stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;

        while (cur || !stk.empty()) {
            while (cur!=nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            if (head==nullptr) {    // 最左下角的节点
                head = cur;
            } else {
                tail->right = cur;  // 将当前节点拼接到尾部
            }
            tail = cur; // 更新尾节点为当前节点
            cur->left = nullptr;    // 断开左子树

            cur = cur->right;   // 访问右子树
        }
        return head;
    }

private:
    void dfs(TreeNode* root, TreeNode*& left, TreeNode*& right) {
        if (!root) return;
        TreeNode* ll = nullptr;
        TreeNode* lr = nullptr;
        TreeNode* rl = nullptr;
        TreeNode* rr = nullptr;
        dfs(root->left, ll, lr);
        dfs(root->right, rl, rr);

        root->left = nullptr;   // 端口左子树

        if (lr) {
            left = ll;
            lr->right = root;
        } else
            left = root;
        if (rl) {
            right = rr;
            root->right = rl;
        } else
            right = root;
        
    }
};