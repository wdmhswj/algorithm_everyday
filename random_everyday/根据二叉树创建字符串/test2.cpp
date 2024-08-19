#include "../../structs/TreeNode.h"
#include <cstddef>
#include <iostream>
#include <string>
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
public:
    string tree2str(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        string s=std::to_string(root->val);
        if (root->left==nullptr && root->right==nullptr) {
            return s;
        }else if(root->right!=nullptr){
            return s+"("+tree2str(root->left)+")"+"("+tree2str(root->right)+")";
        }else{
            return s+"("+tree2str(root->left)+")";
        }
    }


};

int main(){

    TreeNode* root  = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    // root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(4);

    Solution s;
    s.tree2str(root);
}