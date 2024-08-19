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
        string res;
        preorder(root, res, 0);
        return res;
    }

private:
    void preorder(TreeNode* root, string& res, size_t index)
    {
        size_t size1=res.size();
        res.insert(index, std::to_string(root->val));
        size_t size2=res.size();
        index += (size2-size1);
        
        if(root->left==nullptr && root->right==nullptr)
        {   
            std::cout<<res<<std::endl;
            return;
        }else if (root->left==nullptr && root->right!=nullptr) {
            res.insert(index, "()()");
            std::cout<<res<<std::endl;
            // res.insert(index+(size2-size1)+2, "()");
            preorder(root->right, res, index+3);
        }else if(root->left!=nullptr && root->right==nullptr) {
            res.insert(index, "()");
            std::cout<<res<<std::endl;
            // res.insert(index+(size2-size1)+2, "()");
            preorder(root->left, res, index+1);
        }else{
            res.insert(index, "()()");
            std::cout<<res<<std::endl;
            // res.insert(index+(size2-size1)+2, "()");
            int size3=res.size();
            preorder(root->left, res, index+1);
            // res大小可以发生变化
            int size4=res.size();
            preorder(root->right, res, index+3+(size4-size3));
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