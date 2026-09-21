#include <bits/stdc++.h>
using namespace std;


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


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        
        std::unordered_map<Node*, int> hash1; // ptr->idx
        std::unordered_map<int, Node*> hash2; // idx->ptr
        


        Node* newHead = new Node(head->val);
        Node* cur1 = head;
        Node* cur2 = newHead;
        int index = 0;
        hash1[cur1] = index;
        hash2[index] = cur2;
        
        while (cur1->next) {
            cur2->next = new Node(cur1->next->val);
            cur1 = cur1->next;
            cur2 = cur2->next;

            hash1[cur1] = ++index;
            hash2[index] = cur2; 
        }

        cur1 = head;
        cur2 = newHead;
        index = 0;
        while (cur1) {
            if (cur1->random) cur2->random = hash2[hash1[cur1->random]];

            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return newHead;
    }


    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* cur = head;
        std::unordered_map<Node*, Node*> map;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            map[cur]->random = map[cur->random];
            map[cur]->next = map[cur->next];
            cur = cur->next;
        }

        return map[head];
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. 交错复制
        for (Node* cur=head; cur; cur=cur->next->next) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }
        // 2. 设置 random 节点
        for (Node* cur=head; cur; cur=cur->next->next) {
            if (cur->random) cur->next->random = cur->random->next;
        }
        // 3. 分离链表
        Node dummy(0);
        Node* tail = &dummy;
        for (Node* cur=head; cur; cur=cur->next, tail=tail->next) {
            tail->next = cur->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
    }
};

int main() {
    
    return 0;
}