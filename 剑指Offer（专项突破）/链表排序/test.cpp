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
    ListNode* sortList(ListNode* head) {
        // 空节点或只有一个节点
        if (!head || !head->next) return head;

        // 通过快慢指针找到中间节点，将链表切割为2半
        ListNode * slow=head, * fast=head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 切割
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 递归排序左右两半链表
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // 合并2个有序链表
        return _merge(left, right);
    }

private:
    ListNode* _merge(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        ListNode* head = &dummy;
        
        while (l1 && l2) {
            if (l1->val<=l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        head->next = l1 ? l1 : l2;
        return dummy.next;
    }
};