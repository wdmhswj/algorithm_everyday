#include "../../../../structs/TreeNode.h"
#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:

    // 递归法
    int maxDepth(TreeNode* root) {
        // 终止条件
        if (root==nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};