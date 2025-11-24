#include "../../utils/utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast) {
                ListNode* ret = head;
                while (slow!=ret) {
                    slow = slow->next;
                    ret = ret->next;
                }
                return ret;
            }
        }
        return nullptr;
    }
};