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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (!l1) {
            cur->next = l2;
        } else {
            cur->next = l1;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode* trainningPlan1(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* ans = nullptr;
        if (l1->val <= l2->val) {
            ans = trainningPlan1(l1->next, l2);
            l1->next = ans;
            return l1;
        } else {
            ans = trainningPlan1(l1, l2->next);
            l2->next = ans;
            return l2;
        }
    }
};