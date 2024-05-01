#include "../../../structs/TreeNode.h"
#include <climits>
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
    int findMax(const vector<int>& nums, int begin, int end) {
        int res = -1;
        int max=INT_MIN;
       for (int i=begin; i<end; ++i) {
            if (nums[i]>=max) {
                res = i;
                max = nums[i];
            }
       }
        return res;
    }
    TreeNode* helper(vector<int>& nums, int begin, int end) {
        // 找到最大值
        int maxIndex = findMax(nums, begin, end);
        TreeNode* root = new TreeNode(nums[maxIndex]);
        if (begin<maxIndex) {
            root->left=helper(nums, begin, maxIndex);
        }
        if (maxIndex<end-1) {
            root->right=helper(nums, maxIndex+1, end);
        }
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return helper(nums, 0, nums.size());
    }
};