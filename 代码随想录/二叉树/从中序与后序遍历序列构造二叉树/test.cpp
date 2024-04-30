#include "../../../structs/TreeNode.h"
#include <vector>

using std::vector;

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
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, 
                                    vector<int>& postorder, int postorderBegin, int postorderEnd) {
                                        if (inorderBegin==inorderEnd || postorderBegin==postorderEnd) {
                                            return nullptr;
                                        }
                                        // 根节点
                                        TreeNode* root = new TreeNode(postorder[postorderEnd-1]);
                                        if (postorderEnd-postorderBegin==1) {   // 只有一个节点
                                            return root;    
                                        }
                                        

                                    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0 || postorder.size()==0) {
            return nullptr;
        }

    }
};