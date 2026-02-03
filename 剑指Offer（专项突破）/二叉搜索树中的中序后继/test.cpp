#include "../../utils/utils.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root==nullptr) return nullptr;

        TreeNode* successor = nullptr;
        TreeNode* cur = root;
        while (cur!=nullptr) {
            // std::cout << "cur->val=" << cur->val << std::endl;
            if (cur->val==p->val) {
                if (cur->right) {
                    cur = cur->right;
                    while (cur->left!=nullptr) {
                        cur = cur->left;
                    }
                    return cur;
                }
                break;
            } else if (cur->val<p->val) {
                cur = cur->right;
            } else {
                successor = cur;    // 当前节点值大于p，是潜在后继
                cur = cur->left;
            }
        }
        return successor;
    }

    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        if (root==nullptr) return nullptr;

        TreeNode* successor = nullptr;
        TreeNode* cur = root;
        while (cur!=nullptr) {
            if (cur->val>p->val) {
                successor = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return successor;
    }

};

int main() {
    TreeNode* test1 = deserialize("2,1,3,n,n,n,n,", 'n', ',');

}