#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        const int n = temperatures.size();
        std::vector<int> res(n, 0);

        std::stack<int> stk;

        for (int i=0; i<n; ++i) {
            while (!stk.empty() && temperatures[i]>temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return res;
    }
};