#include "../../structs/ListNode.h"
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

#include <vector>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return true;
        }

        
        ListNode* p=head;
        int len = 0;
        while (p!=nullptr) {
            ++len;
            p = p->next;
        }
        std::vector<int> record(len, 0);
        auto it = record.begin();
        p = head;
        while (p!=nullptr) {
            *it = p->val;
            ++it;
            p = p->next;
        }
        it = record.begin();
        auto rit = record.rbegin();
        while (it!=record.end() && rit!=record.rend()) {
            if(*it != *rit)
                return false;
            ++it;
            ++rit;
        }
        return true;
    }

    bool isPalindrome2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head; // 慢指针，找到链表中间分位置，作为分割
        ListNode* fast = head;
        ListNode* pre = head; // 记录慢指针的前一个节点，用来分割链表
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 分割链表

        ListNode* cur1 = head;  // 前半部分
        ListNode* cur2 = reverseList(slow); // 反转后半部分，总链表长度如果是奇数，cur2比cur1多一个节点

        // 开始两个链表的比较
        while (cur1) {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};