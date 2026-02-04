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
class BSTIterator {
public:
    BSTIterator(TreeNode* root): _cur(root) {
    }
    
    int next() {
        while (_cur) {
            _stk.push(_cur);
            _cur = _cur->left;
        }
        _cur = _stk.top(); _stk.pop();
        int ret = _cur->val;
        _cur = _cur->right;
        return ret;
    }
    
    bool hasNext() {
        return _cur || !_stk.empty();
    }
private:
    std::stack<TreeNode*> _stk;
    TreeNode* _cur;

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */