#include "../../../../structs/Node.h"

#include <cstddef>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> res;
        if (root==nullptr) {
            return res;
        }
        queue<Node*> que;
        que.push(root);
        Node* node = nullptr;   // 辅助指针
        while (!que.empty()) {
            int size = que.size();  // 获取当前层节点的个数
            vector<int> vec;
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                vec.push_back(node->val);
                // 遍历子节点
                for (Node* child: node->children) {
                    if (child!=nullptr) {
                        que.push(child);
                    }
                }
            }
            res.push_back(vec); // 当前层结果放入结果集
        }
        return res;
    }
};