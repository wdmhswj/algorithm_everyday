
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../../structs/TreeNode.h"
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
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }

        if(hash.find(k-root->val)!=hash.end())
        {
            return true;
        }

        hash.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
        
    }   
    bool findTarget2(TreeNode* root, int k) {
        
        // 中序遍历获得有序数组
        inorder_traversal(root);

        // 双指针法
        int l=0, r=vec.size()-1;
        while(l<r){
            int sum=vec[l]+vec[r];
            if(sum==k)
                return true;
            else if(sum<k)
                ++l;
            else
                --r;
        }
        return false;

    }   
private:
    std::unordered_set<int> hash;
    std::vector<int> vec;
    
    void inorder_traversal(TreeNode* root)
    {
        if(!root)
            return;
        inorder_traversal(root->left);
        vec.push_back(root->val);
        inorder_traversal(root->right);
    }
    
};