class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        // 链表为空
        if (head==nullptr) {
            node->next = node;
            return node;
        }

        Node* cur = head;
        while (cur->next != head) {
            if ((cur->val<=insertVal && insertVal<=cur->next->val)
                || (cur->val>cur->next->val && (insertVal>=cur->val || insertVal<=cur->next->val)) )
                break;
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};