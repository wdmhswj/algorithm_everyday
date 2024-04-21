#include <algorithm>
#include <vector>
#include <stack>
#include "../../../structs/TreeNode.h"

using std::vector;
using std::stack;


class Solution {
public:

    // 递归法
   vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper_preorder(res, root);
        return res;
    }
    void helper_preorder(vector<int>& vec, TreeNode* root){
        // 终止条件
        if(root==nullptr) return;
        vec.push_back(root->val);   // 中
        helper_preorder(vec, root->left);   // 左
        helper_preorder(vec, root->right);   // 右
    }

    // 迭代法：前序
    vector<int> preorderTraversal_1(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* tmp = stack.top();
            res.push_back(tmp->val);
            stack.pop();
            if (tmp->right!=nullptr) {
                stack.push(tmp->right);
            }
            if (tmp->left!=nullptr) {
                stack.push(tmp->left);
            }
        }
        return res;
    }

    // 中序
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur!=nullptr || !stack.empty()) {
            if (cur!=nullptr) {
                stack.push(cur);    // 中
                cur = cur->left;    
            } else {
                cur = stack.top();
                stack.pop();
                res.push_back(cur->val);    // 左
                cur = cur->right;   // 右
            }
        }
        return res;

    }

    // 后序：前序的中左右->中右左，结果res反向变为左右中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* tmp = stack.top();
            res.push_back(tmp->val);
            stack.pop();
            if (tmp->left!=nullptr) {
                stack.push(tmp->left);
            }
            if (tmp->right!=nullptr) {
                stack.push(tmp->right);
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    // 后序：直接写，使用pre记录是否已经访问右子树
    vector<int> postorderTraversal_1(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (cur!=nullptr || !stack.empty()) {
            while (cur!=nullptr) {
                stack.emplace(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            if (cur->right==nullptr || pre==cur->right) {
                res.emplace_back(cur->val);
                pre = cur;
                cur = nullptr;
            } else {
                stack.emplace(cur); // 中间节点重新入栈
                cur = cur->right;   // 访问右子树
            }
        }
       
        return res;
    }

};