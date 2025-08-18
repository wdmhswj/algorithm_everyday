// #include "../../utils/utils.h"

#include <stack>
#include <iostream>
#include <functional>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = nullptr;
        std::stack<Node*> st;
        Node* cur = root;
        Node* pre = nullptr;

        while (cur!=nullptr || !st.empty()) {
            while (cur!=nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre!=nullptr) {
                pre->right = cur;
            } else {
                head = cur;
            }
            cur->left = pre;
            
            pre = cur;
            cur = cur->right;
        }
        if (head && pre) {
            pre->right = head;
            head->left = pre;
        }
        return head;
    }

    Node* treeToDoublyList1(Node* root) {
        Node* head = nullptr;
        std::stack<Node*> st;
        Node* cur = root;
        Node* pre = nullptr;

        std::function<void(Node*)> dfs = [&](Node* root) {
            if (root==nullptr) return;
            dfs(root->left);
            if (pre!=nullptr) {
                pre->right = root;
            } else {
                head = root;
            }
            root->left = pre;
            pre = root;
            dfs(root->right);
        };

        dfs(root);
        if (head && pre) {
            pre->right = head;
            head->left = pre;
        }
        return head;
    }
};

int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    Node* head = sol.treeToDoublyList(root);
    // Print the doubly linked list
    Node* curr = head;
    do {
        std::cout << curr->val << " ";
        curr = curr->right;
    } while (curr != head);
    std::cout << std::endl;
    return 0;
}