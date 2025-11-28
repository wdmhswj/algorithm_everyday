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
    bool isPalindrome(ListNode* head) {
        std::stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast && fast->next==nullptr) // 奇数个节点
            slow = slow->next;
        while (slow && !st.empty()) {
            if (slow->val != st.top())
                return false;
            st.pop();
            slow = slow->next;
        }
        return true;
    }

    bool isPalindrome1(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow->next; // 右半部分第一个节点
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while (pre) {
            if (head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};