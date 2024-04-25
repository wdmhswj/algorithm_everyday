#include "../../../structs/nNode.h"
#include <queue>
// #include <utility>
// #include <vector>
// #include <stack>

// using std::vector;
// using std::stack;
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
    // 递归法
    int maxDepth(Node* root) {
        // 终止条件
        if (root==nullptr) {
            return 0;
        }
        int max = 0;
        for (Node* node : root->children) {
            int depth = maxDepth(node);
            if (max<depth) {
                max=depth;
            }
        }
        return 1 + max;
    }
    // 层序遍历法
    int maxDepth_1(Node* root) {
        if (root==nullptr) {
            return 0;
        }
        // 辅助队列
        queue<Node*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            Node* node = nullptr;
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                for (Node* child : node->children) {
                    if (child!=nullptr) {
                        que.push(child);
                    }
                }
            }
            ++depth;
        }
        return depth;
    }
};