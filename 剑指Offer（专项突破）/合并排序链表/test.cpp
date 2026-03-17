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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l, ListNode* r) {
            return l->val > r->val; // 小根堆
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* list: lists) {
            if (list) pq.push(list);
        }

        ListNode dummy{};
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            tail->next = node;
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }


    ListNode* mergeKLists_1(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return _merge(lists, 0, lists.size()-1);
    }

private:
    ListNode* _merge(std::vector<ListNode*>& lists, int l, int r) {
        if (l==r) return lists[l];
        if (l>r) return nullptr;

        int mid = l + (r-l)/2;
        ListNode* left = _merge(lists, l, mid);
        ListNode* right = _merge(lists, mid+1, r);

        return _mergeTwo(left, right);
    }

    ListNode* _mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val<=l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};