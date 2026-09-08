#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        const int n = prices.size();
        std::vector<int> res(prices.begin(), prices.end());

        std::stack<int> stk;

        for (int i=0; i<n; ++i) {
            while (!stk.empty() && prices[i]<=prices[stk.top()]) {
                res[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        return res;
    }
};