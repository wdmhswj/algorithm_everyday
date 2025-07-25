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
    // 反转数组
    std::vector<int> reverseBookList(ListNode* head) {
        std::vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        std::reverse(arr.begin(), arr.end());
        return arr;
    }

    // 递归
    std::vector<int> reverseBookList_1(ListNode* head) {
        if (head==nullptr)
        {
            return {};
        }
        std::vector<int> arr = reverseBookList_1(head->next);
        arr.push_back(head->val);
        return arr;
    }
};