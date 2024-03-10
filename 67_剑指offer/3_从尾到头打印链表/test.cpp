#include"../../structs/ListNode.h"
#include<vector>
#include<algorithm>

using namespace std;

// 先前向保存，再reverse
vector<int> printListFromTailToHead(ListNode* head){
    if(head==nullptr) return {};    // 假设没有头节点
    vector<int> res;
    while(head != nullptr){
        res.push_back(head->data);
        head=head->next;
    }
    reverse(res.begin(), res.end());    // 使用标准库函数反向
    return res;
}

// 不用reverse，使用反向迭代器，返回一个逆序也行
vector<int> printListFromTailToHead2(ListNode* head){
    if(head==nullptr) return {};    // 假设没有头节点
    vector<int> res;
    while(head != nullptr){
        res.push_back(head->data);
        head=head->next;
    }
    return vector<int>(res.rbegin(), res.rend());
}