#include "../../../structs/TreeNode.h"
#include <queue>
#include <utility>
// #include <vector>
#include <stack>

// using std::vector;
using std::stack;
using std::queue;

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
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) {
            return nullptr;
        }
        helper_swap(root);
        return root;
    }

    // void helper_swap(TreeNode* left, TreeNode* right){
    //     if (left!=nullptr) {
    //         helper_swap(left->left, left->right);
    //     }
    //     if (right!=nullptr) {
    //         helper_swap(right->left, right->right);
    //     }
    //     auto tmp = left;
    //     left = right;
    //     right = tmp;

    // }
    void helper_swap(TreeNode* parent){
        // 先交换左右节点
        auto tmp = parent->left;
        parent->left = parent->right;
        parent->right = tmp;

        // 递归调用
        if (parent->left!=nullptr) {
            helper_swap(parent->left);
        }
        if (parent->right!=nullptr) {
            helper_swap(parent->right);
        }
    }
    
    // 迭代法
    TreeNode* invertTree_1(TreeNode* root) {
        if (root==nullptr) {
            return nullptr;
        }
        stack<TreeNode*> st;    // 辅助栈
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node!=nullptr) {    // 第一此访问节点
                if (node->right!=nullptr) {
                    st.push(node->right);   // 右
                }
                if (node->left!=nullptr) {
                    st.push(node->left);    // 左
                }
                st.push(node);
                st.push(nullptr);
            } else {
                node = st.top();
                st.pop();
                std::swap(node->left, node->right);
            }
        }
        return root;
    }

    // 层序遍历法
    TreeNode* invertTree_2(TreeNode* root) {
        if (root==nullptr) {
            return nullptr;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; i++) {
                TreeNode* node = que.front();
                que.pop();
                std::swap(node->left, node->right);
                if (node->left!=nullptr) {
                    que.push(node->left);
                }
                if (node->right!=nullptr) {
                    que.push(node->right);
                }
            }
        }
        return root;
    }

};