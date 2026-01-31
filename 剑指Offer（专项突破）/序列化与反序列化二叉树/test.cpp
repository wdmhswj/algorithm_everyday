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
        if (root==nullptr) return {};
        std::queue<TreeNode*> q;
        q.push(root);
        int sz = 0;
        TreeNode* node = nullptr;
        std::string rt;
        while (!q.empty()) {
            sz = q.size();
            for (int i=0; i<sz; ++i) {
                node = q.front(); q.pop();
                if (node) {
                    rt += std::to_string(node->val)+',';
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    rt += "n,";
                }
            }
        }
        return rt;
    }

    std::string serialize1(TreeNode* root) {
        if (root==nullptr) return "n,";
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = nullptr;
        std::ostringstream oss;
        while (!q.empty()) {
            node = q.front(); q.pop();
            if (node) {
                oss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                oss << "n,";
            }
        }
        return oss.str();
    }

    std::string serialize2(TreeNode* root) {
        if (root==nullptr) return "";
        std::ostringstream oss;
        preorder_serialize(root, oss);
        return oss.str();
    }

    void preorder_serialize(TreeNode* root, std::ostringstream& s) {
        if (root==nullptr)
            s << "n ";
        else {
            s << root->val << " ";
            preorder_serialize(root->left, s);
            preorder_serialize(root->right, s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;

        std::vector<std::string> nodes;
        data.pop_back();    // 去除末尾的分隔符
        std::stringstream ss(data);
        std::string item;
        while (std::getline(ss, item, ',')) {
            if (!item.empty()) nodes.push_back(item);
        }

        TreeNode* root = new TreeNode(std::stoi(nodes[0]));
        std::queue<TreeNode*> q;
        q.push(root);
        int sz = 0;
        TreeNode* node = nullptr;

        int index = 1;
        while (!q.empty() && index<nodes.size()) {
            sz = q.size();
            for (int i=0; i<sz; ++i) {
                node = q.front(); q.pop();
                if (index<nodes.size() && nodes[index]!="n") {
                    node->left = new TreeNode(std::stoi(nodes[index]));
                    q.push(node->left);
                }
                ++index;
                if (index<nodes.size() && nodes[index]!="n") {
                    node->right = new TreeNode(std::stoi(nodes[index]));
                    q.push(node->right);
                }
                ++index;
            }
        }
        return root;
    }

    TreeNode* deserialize1(std::string data) {
        if (data=="n,") return nullptr;

        std::stringstream ss(data);
        std::string item;

        // 读取根节点
        std::getline(ss, item, ',');
        TreeNode* root = new TreeNode(std::stoi(item));

        // 队列
        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* node = nullptr;
        while (!q.empty()) {
            node = q.front(); q.pop();
            std::getline(ss, item, ',');
            if (item!="n") {
                node->left = new TreeNode(std::stoi(item));
                q.push(node->left);
            }
            std::getline(ss, item, ',');
            if (item!="n") {
                node->right = new TreeNode(std::stoi(item));
                q.push(node->right);
            }
        }
        return root;
    }

    TreeNode* deserialize2(std::string data) {
        if (data.empty()) return nullptr;

        std::istringstream iss(data);
        return preorder_deserialize(iss);
    }
    TreeNode* preorder_deserialize(std::istringstream& iss) {
        std::string item;
        iss >> item;
        if (item=="n") return nullptr;
        TreeNode* root = new TreeNode(std::stoi(item));
        root->left = preorder_deserialize(iss);
        root->right = preorder_deserialize(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));