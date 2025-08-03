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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        for (ListNode* cur=dummy; cur->next; cur = cur->next) {
            if (cur->next->val==val) {
                // ListNode* target = cur->next;
                cur->next = cur->next->next;
                // delete target;
                break;
            }
        }
        ListNode* tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};