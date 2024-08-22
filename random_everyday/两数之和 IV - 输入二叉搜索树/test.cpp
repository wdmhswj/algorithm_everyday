
#include <iostream>
#include <queue>
#include <unordered_set>
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
        if(!root) return false;
        
        // 前序遍历
        TreeNode* cur = root;
        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            cur=que.front();
            que.pop();
            if(k-cur->val!=cur->val)
            {
                if(help(root, k-cur->val))
                {
                    return true;
                }
            }
            
            if(cur->left)
            {
                que.push(cur->left);
            }
            if(cur->right)
            {
                que.push(cur->right);
            }
        }
        return false;
        
    }   
private:
    std::unordered_set<int> set;

    bool help(TreeNode* root, int sub_k)
    {
        if(!root) return false;
        set.insert(root->val);  // 将当前已遍历过的元素值记录

        if(set.find(sub_k)!=set.end())  // 已经遍历过了
            return true;
        if(root->val==sub_k)
        {
            return true;
        }else if(sub_k<root->val)
        {
            return help(root->left, sub_k);
        }else{
            return help(root->right, sub_k);
        }
    }
};