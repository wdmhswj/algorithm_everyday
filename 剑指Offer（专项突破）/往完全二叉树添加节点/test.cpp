#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        std::queue<TreeNode*> que{{root}};
        while (!que.empty()) {
            for (int i=que.size(); i>0; --i) {
                TreeNode* node = que.front(); que.pop();
                _tree.push_back(node);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* p_node = _tree[(_tree.size()-1)/2];
        TreeNode* n_node = new TreeNode(v);
        if (!p_node->left) p_node->left = n_node;
        else p_node->right = n_node;
        _tree.push_back(n_node);
        return p_node->val;
    }
    
    TreeNode* get_root() {
        return _tree.front();
    }
private:
    std::vector<TreeNode*> _tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */