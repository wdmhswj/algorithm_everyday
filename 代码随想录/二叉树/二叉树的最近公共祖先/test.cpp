#include <cstddef>
#include <stack>
#include <unordered_map>
#include "../../../structs/TreeNode.h"

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
private:
    bool isInTree(TreeNode* root, TreeNode* p) {
        if (root==nullptr) {
            return false;
        }
        if (root==p) {
            return true;
        }
        return isInTree(root->left, p) || isInTree(root->right, p);
    }
    bool isInTree_1(TreeNode* root, TreeNode* p) {
        if (root==nullptr) {
            return false;
        }
        std::stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node==p) {
                return true;
            }
            if (node->right) {
                st.push(root->right);
            }
            if (node->left) {
                st.push(root->left);
            }
        }
        return false;
    }

    void dfs(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& father) {
        if (root->left) {
            father[root->left]=root;
            dfs(root->left, father);
        }
        if (root->right) {
            father[root->right]=root;
            dfs(root->right, father);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root==p || root==q) {
            return root;
        }
        if (isInTree(root->left, p) && isInTree(root->right, q) || isInTree(root->left, q) && isInTree(root->right, p)) {
            return root;
        } else if (isInTree(root->left, p) && isInTree(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        } else{
            return lowestCommonAncestor(root->right, p, q);
        }
    }

    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr || root==p || root==q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left!=nullptr && right!=nullptr) {
            return root;
        } else if (left==nullptr) {
            return right;
        } else {
            return left;
        }
    
    }

    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
        }
        std::unordered_map<TreeNode*, TreeNode*>father;
        father[root]=nullptr;
        dfs(root, father);

        std::unordered_map<TreeNode*, bool> isVisited;
        TreeNode* node = p;
        while (node) {
            isVisited[node]=true;
            node = father[node];
        }
        node = q;
        while (node) {
            if (isVisited[node]) {
                return node;
            }
            node = father[node];
        }
        return nullptr;
    }
};