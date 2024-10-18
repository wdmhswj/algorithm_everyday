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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 0个或1个节点的情况
        if(head==nullptr || head->next==nullptr)
            return head;

        ListNode* front = nullptr;
        ListNode* cur = nullptr;
        ListNode* next = nullptr;
        ListNode* nn = nullptr;
        ListNode* new_head = head->next;

        cur = head;
        while (cur!=nullptr) {
            // 更新 next, nn
            next = cur->next;
            if(next==nullptr)   // 奇数个情况下，最后一个节点
                break;  
            nn = next->next;

            // 交换
            if(front!=nullptr)
                front->next = next;
            next->next = cur;
            cur->next = nn;
            
            // 更新 cur, front
            front = cur;
            cur = nn;
        }

        return new_head;
    }
};