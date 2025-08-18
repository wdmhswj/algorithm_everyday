
#include "../../utils/utils.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = nullptr;
        std::string rt;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur) {
                rt += std::to_string(cur->val)+" ";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                rt += "# ";
            }
        }
        rt.pop_back();
        return rt;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;
        std::stringstream ss;
        ss << data;
        std::string tmp;
        ss >> tmp;
        TreeNode* root = new TreeNode(std::stoi(tmp));
        std::queue<TreeNode*> q{{root}};
        TreeNode* cur = nullptr;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            ss >> tmp;
            if (tmp!="#") {
                cur->left = new TreeNode(std::stoi(tmp));
                q.push(cur->left);
            }
            ss >> tmp;
            if (tmp!="#") {
                cur->right = new TreeNode(std::stoi(tmp));
                q.push(cur->right);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));