#include "../../../structs/TreeNode.h"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {  // 未访问过
                st.pop();   // 弹出
                if (node->right != nullptr) {
                    st.push(node->right);   // 添加右节点
                }
                st.push(node); 
                st.push(nullptr);   // 中节点已访问过，添加null作为标记
                if (node->left != nullptr) {
                    st.push(node->left);
                }
            } else {    // 遇到null，代表紧随其后的节点已访问过，需要处理
                st.pop();   // 弹出空节点
                node = st.top();    // 取出要处理的节点
                st.pop();
                res.push_back(node->val);   // 加到结果集中
            }
        }
        return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {  // 未访问过
                st.pop();   // 弹出
                if (node->right != nullptr) {
                    st.push(node->right);   // 添加右节点
                }
                if (node->left != nullptr) {    // 左
                    st.push(node->left);
                }
                st.push(node); 
                st.push(nullptr);   // 中节点已访问过，添加null作为标记
                
            } else {    // 遇到null，代表紧随其后的节点已访问过，需要处理
                st.pop();   // 弹出空节点
                node = st.top();    // 取出要处理的节点
                st.pop();
                res.push_back(node->val);   // 加到结果集中
            }
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {  // 未访问过
                st.pop();   // 弹出
                 st.push(node); 
                st.push(nullptr);   // 中节点已访问过，添加null作为标记
                if (node->right != nullptr) {
                    st.push(node->right);   // 添加右节点
                }
                if (node->left != nullptr) {    // 左
                    st.push(node->left);
                }
               
            } else {    // 遇到null，代表紧随其后的节点已访问过，需要处理
                st.pop();   // 弹出空节点
                node = st.top();    // 取出要处理的节点
                st.pop();
                res.push_back(node->val);   // 加到结果集中
            }
        }
        return res;
    }
    
};