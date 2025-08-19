#include "../../utils/utils.h"

class Solution {
public:
    int maxSales(std::vector<int>& sales) {
        const int n = sales.size();
        std::vector<int> f(n+1, 0);
        int rt = INT_MIN;
        for (int i=1; i<=n; ++i)
        {
            f[i] = std::max(0, f[i-1]) + sales[i-1];
            rt = std::max(rt, f[i]);
        }
        return rt;
    }

    int maxSales1(std::vector<int>& sales) {
        int f = 0;
        int rt = INT_MIN;
        for (const int& e: sales)
        {
            f = std::max(0, f) + e;
            rt = std::max(rt, f);
        }
        return rt;
    }
};