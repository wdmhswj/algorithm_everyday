#include "../../utils/utils.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* new_dummy = new Node(-1);
        Node* front_n = new_dummy;

        std::unordered_map<Node*, Node*> map;
        while (cur) {
            Node* new_node = new Node(cur->val);
            front_n->next = new_node;
            map[cur] = new_node;
            cur = cur->next;
            front_n = front_n->next;
        }

        cur = head;
        front_n = new_dummy;
        while (cur) {
            front_n->next->random = map[cur->random];
            cur = cur->next;
            front_n = front_n->next;
        }
        Node* rt = new_dummy->next;
        delete new_dummy;
        return rt;
    }

    Node* copyRandomList1(Node* head) {
        if (!head) return nullptr;

        for (Node* cur=head; cur;) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }

        for (Node* cur=head; cur; cur=cur->next->next) {
            if (cur->random)
                cur->next->random = cur->random->next;
        }

        Node* rt = head->next;

        // for (Node* cur=head; cur;) {
        //     Node* origin_next = cur->next->next;
        //     if (origin_next) 
        //         cur->next->next = cur->next->next->next;
        //     cur->next = origin_next;
        //     cur = cur->next;
        // }
        for (Node* cur=head; cur;) {
            Node* next = cur->next;
            if (next) cur->next = next->next;
            cur = next;
        }

        return rt;
    }
};