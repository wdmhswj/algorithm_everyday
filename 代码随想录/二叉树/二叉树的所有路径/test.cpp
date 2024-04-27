#include "../../../structs/TreeNode.h"
#include <string>
#include <vector>
#include <stack>

using std::vector;
using std::string;

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
    void pre_traversal(TreeNode* cur, string path,  vector<string>& result) {
        path += std::to_string(cur->val);   // 中
        if (cur->left==nullptr && cur->right==nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left!=nullptr) {
            pre_traversal(cur->left, path+"->", result);    // 左
        }
        if (cur->right!=nullptr) {
            pre_traversal(cur->right, path+"->", result);    // 右
        }
    }
public:
    // 递归法
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        vector<string> res;
        string path;
        pre_traversal(root, path, res);
        return res;

    }
    // 迭代化
    vector<string> binaryTreePaths_1(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        vector<string> res;
        std::stack<TreeNode*> st;  // 辅助队列：节点
        std::stack<string> pathSt;  // 辅助队列：每个元素是对应于节点队列的元素的路径

        st.push(root);
        pathSt.push(std::to_string(root->val));
        // string record = std::to_string(root->val);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            string path = pathSt.top();
            pathSt.pop();

            if (node!=nullptr) {
                if (node->right!=nullptr) {
                    st.push(node->right);
                    pathSt.push(path + "->" + std::to_string(node->right->val));
                }
                if (node->left!=nullptr) {
                    st.push(node->left);
                    pathSt.push(path + "->" + std::to_string(node->left->val));
                }
                st.push(node);
                pathSt.push(path);
                st.push(nullptr);
            } else {
                node = st.top();
                st.pop();

                if (node->left==nullptr && node->right==nullptr) {
                    res.push_back(path);
                }
            }

        }
        return res;

    }
};