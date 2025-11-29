// #include "../../utils/utils.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        _flatten(head);
        return head;        
    }
private:
    Node* _flatten(Node* cur) {
        Node* tail = nullptr;

        while (cur) {
            Node* next = cur->next;
            if (!cur->child)
                tail = cur;
            else {
                Node* child = cur->child;   // 之后需要将cur->child置为空
                tail = _flatten(child); // 获取子链表的最后一个节点
                cur->child = nullptr;   // 置空
                child->prev = cur;
                cur->next = child;
                tail->next = next;
                if (next) next->prev = tail;    // 检查next是否为空
            }
            cur = next;
        }
        return tail;
    }
};