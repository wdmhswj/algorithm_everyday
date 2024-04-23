#include "../../../../structs/nextNode.h"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr) {
            return nullptr;
        }
        queue<Node*> que;
        que.push(root);
        Node* node = nullptr;   // 辅助指针
        while (!que.empty()) {
            int size = que.size();  // 获取当前层节点的个数
            Node* pre = nullptr;    // 指向上一个左边节点
            for (int i=0; i<size; ++i) {
                node = que.front();
                que.pop();
                if (pre!=nullptr) {
                    pre->next = node;
                }
                pre = node;
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            pre->next=nullptr;
        }
        return root;
    }
};