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
    void reorderList(ListNode* head) {
        ListNode* mid = this->getMidNode(head);
        ListNode* mid_next = mid->next;
        mid->next = nullptr; // 断开左右两个子链表
        ListNode* reversed_sub_list = this->reverseList(mid_next);
        head = this->merge2Lists(head, reversed_sub_list);
    }

private:
    // 对于奇数个节点的链表返回中间节点，对于偶数个节点的链表返回右半部分第一个节点
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 合并两个链表，l1元素位于首位
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (l1 && l2) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};