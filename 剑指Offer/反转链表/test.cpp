#include "../../utils/utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* trainningPlan(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode* trainningPlan1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* ans = trainningPlan1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }
};