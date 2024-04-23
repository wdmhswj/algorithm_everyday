#include "../../../../structs/TreeNode.h"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root==nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* node = nullptr;   // 辅助指针
        while (!que.empty()) {
            int size = que.size();  // 获取当前层节点的个数
            double sum = 0;
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                sum+=node->val;
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(sum/size); // 当前层结果放入结果集
        }
        return res;
    }
};