#include "../../../utils/utils.h"

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::array<int, 26> cnt{};
        for (char c: s) {
            ++cnt[c-'a'];
        }

        std::stack<int> stk;
        std::array<bool, 26> inRes{};
        for (char c: s) {
            int c_idx = c-'a';
            if (!inRes[c_idx]) { // 当前字符还未进入字符串中
                while (!stk.empty() && c_idx<stk.top() && cnt[stk.top()]>0) { // 非空 && 当前字符字典序更小 && 栈顶元素后续还有
                    int top = stk.top();
                    stk.pop();
                    inRes[top] = false;
                }
                stk.push(c_idx);
                inRes[c_idx] = true;
            }
            --cnt[c_idx]; // 无论是否入栈，计数都要-1

        }

        std::string res;
        while (!stk.empty()) {
            res.push_back(stk.top() + 'a');
            stk.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};