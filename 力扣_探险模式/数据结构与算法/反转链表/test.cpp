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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* cur = head;
        ListNode* newHead = nullptr;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }

    ListNode* reverseList_1(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList_1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main() {
    
    return 0;
}