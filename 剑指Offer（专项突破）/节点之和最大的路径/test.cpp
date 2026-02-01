#include "../../utils/utils.h"
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
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) return 0;
            int left = std::max(0, dfs(root->left));
            int right = std::max(0, dfs(root->right));
            ret = std::max(ret, root->val+left+right);
            return root->val + std::max(left, right);
        };
        dfs(root);
        return ret;
    }

    // 以下函数考虑的路径是只能从根节点出发以父节点到子节点方向前进
    int maxPathSum1_false(TreeNode* root) {
        int ret = INT_MIN;
        std::function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int preMaxSum) {
            int maxSum = std::max(node->val, node->val+preMaxSum);
            ret = std::max(ret, maxSum);

            std::cout << "Current Node->val=" << node->val << ", preMaxSum=" << preMaxSum << ", maxSum=" << maxSum << ", ret=" << ret << std::endl;
            if (node->left) dfs(node->left, maxSum);
            // std::cout << "maxSum=" << maxSum << std::endl;
            if (node->right) dfs(node->right, maxSum);
        };
        dfs(root, 0);
        return ret;
    }
};



int main() {
    int mps;

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    
    mps = Solution{}.maxPathSum(root);
    
    TreeNode* root1 = deserialize("-10 9 20 n n 15 7 n n n n", 'n', ' ');

    mps = Solution{}.maxPathSum(root1);

    deleteTreeNode(root);
    deleteTreeNode(root1);


}