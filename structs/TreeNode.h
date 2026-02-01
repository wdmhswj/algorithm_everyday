#pragma once
#include <queue>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// 层序遍历序列化二叉树
std::string serialize(TreeNode* root, char nullNodeChar, char separator) {
    if (root==nullptr) return std::to_string(nullNodeChar) + std::to_string(separator);
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* node = nullptr;
    std::ostringstream oss;
    while (!q.empty()) {
        node = q.front(); q.pop();
        if (node) {
            oss << node->val << separator;
            q.push(node->left);
            q.push(node->right);
        } else {
            oss << nullNodeChar << separator;
        }
    }
    return oss.str();
}


TreeNode* deserialize(std::string data, char nullNodeChar, char separator) {
    if (data.size()==2 && data[0]==nullNodeChar && data[1]==separator) return nullptr;

    std::stringstream ss(data);
    std::string item;

    // 读取根节点
    std::getline(ss, item, separator);
    TreeNode* root = new TreeNode(std::stoi(item));

    // 队列
    std::queue<TreeNode*> q;
    q.push(root);

    TreeNode* node = nullptr;
    while (!q.empty()) {
        node = q.front(); q.pop();
        std::getline(ss, item, separator);
        if (!(item.size()==1 && item[0]==nullNodeChar)) {
            node->left = new TreeNode(std::stoi(item));
            q.push(node->left);
        }
        std::getline(ss, item, separator);
        if (!(item.size()==1 && item[0]==nullNodeChar)) {
            node->right = new TreeNode(std::stoi(item));
            q.push(node->right);
        }
    }
    return root;
}


void deleteTreeNode(TreeNode* root) {
    if (!root) return;
    deleteTreeNode(root->left);
    deleteTreeNode(root->right);
    delete root;
}