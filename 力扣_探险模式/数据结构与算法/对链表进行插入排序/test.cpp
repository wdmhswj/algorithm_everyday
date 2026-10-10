

#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// head = [4,2,1,3]
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* newHead = nullptr;
        while (cur) {
            ListNode* next = cur->next; // 下一个节点
            if (newHead) {
                // 在升序链表中找到位置并插入
                if (cur->val < newHead->val) { // 插入头部
                    cur->next = newHead;
                    newHead = cur;
                } else {
                    ListNode* tmp = newHead;
                    while (tmp->next) {
                        if (cur->val < tmp->next->val) {
                            cur->next = tmp->next;
                            tmp->next = cur;
                            break;
                        }
                        tmp = tmp->next;
                    }
                    if (!tmp->next) { // 插入末尾
                        tmp->next = cur;
                        cur->next = nullptr;
                    }
                }
            } else {
                newHead = cur; // 第一个节点
                cur->next = nullptr;
            }
            
            cur = next;
        }
        return newHead;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode dummy(0);
        
        while (cur) {
            ListNode* next = cur->next;
            ListNode* tmp = &dummy;
            while (tmp->next && tmp->next->val<=cur->val) {
                tmp = tmp->next;
            }
            cur->next = tmp->next;
            tmp->next = cur;

            cur = next;
        }
        return dummy.next;
    }
};

int main() {
    
    return 0;
}