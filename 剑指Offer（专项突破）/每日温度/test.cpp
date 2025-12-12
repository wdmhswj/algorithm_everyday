#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        const int n = temperatures.size();
        std::vector<int> ret(n, 0); // 初始值为 0，对应右边不存在更大的值
        std::stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && temperatures[i]>temperatures[st.top()]) {
                ret[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;

    }
};