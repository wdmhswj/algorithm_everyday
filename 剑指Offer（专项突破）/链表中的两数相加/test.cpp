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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1;
        std::stack<int> s2;

        ListNode* node = l1;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        node = l2;
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* dummy = new ListNode(0);
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top();
                s2.pop();
            }

            ListNode* node = new ListNode(carry%10, dummy->next);
            dummy->next = node;
            carry /= 10;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        std::stack<int> s1;
        std::stack<int> s2;

        ListNode* node = l1;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        node = l2;
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top();
                s2.pop();
            }

            ListNode* node = new ListNode(carry%10, head);
            head = node;
            carry /= 10;
        }
        return head;
    }
};