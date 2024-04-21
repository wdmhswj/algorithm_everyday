#include <vector>
#include "../../../structs/TreeNode.h"

using std::vector;


class Solution {
public:

    // 前序
    void pre_traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        pre_traversal(cur->left, vec);  // 左
        pre_traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        pre_traversal(root, result);
        return result;
    }

    // 中序
    void mid_traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
       
        mid_traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        mid_traversal(cur->right, vec); // 右
    }
    // 后序
    void post_traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
       
        post_traversal(cur->left, vec);  // 左
        post_traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }

};