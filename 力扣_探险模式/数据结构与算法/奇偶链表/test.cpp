#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        while (even->next && even->next->next) {
            odd->next = even->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        // 奇数个节点
        if (even->next && !even->next->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = nullptr;   // 关键：断开偶数链表尾部，避免成环
        }

        odd->next = even_head;
        return head;
    }
};

int main() {
    
    return 0;
}