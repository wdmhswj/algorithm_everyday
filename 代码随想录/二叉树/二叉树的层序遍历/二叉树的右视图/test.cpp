#include "../../../../structs/TreeNode.h"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    // 自底向上的层序遍历
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* node = nullptr;   // 辅助指针
        while (!que.empty()) {
            int size = que.size();  // 获取当前层节点的个数

            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                if (i==size-1) {
                    res.push_back(node->val);
                }
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};