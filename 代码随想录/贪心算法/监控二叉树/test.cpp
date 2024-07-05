#include "../../../structs/TreeNode.h"

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
    int res = 0;
    int traversal(TreeNode* node){
        // 状态：0为未覆盖，1为摄像头，2为已覆盖
        if (node==nullptr) {
            return 2;  
        }
        int left = traversal(node->left);
        int right = traversal(node->right);
        
        if (left==2&&right==2) {    // 左右孩子均被之前的摄像头覆盖，则当前节点应为被之后父节点覆盖，目前还未被覆盖
            return 0;
        } else if (left==0 || right==0) {   // 左右孩子只要有1个未覆盖，则当前节点未摄像头
            ++res;
            return 1;
        } else {    // 左右孩子有摄像头或已覆盖，当前节点之后被覆盖
            return 2;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root)==0) {
            ++res;
        }
        return res;
    }
};