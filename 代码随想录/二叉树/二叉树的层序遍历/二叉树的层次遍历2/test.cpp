#include "../../../../structs/TreeNode.h"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    // 自底向上的层序遍历
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root==nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* node = nullptr;   // 辅助指针
        while (!que.empty()) {
            int size = que.size();  // 获取当前层节点的个数
            vector<int> vec;
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(vec); // 当前层结果放入结果集
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};