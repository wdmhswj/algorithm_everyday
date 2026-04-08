#include "../../utils/utils.h"

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        const int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        std::vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<n; ++i) {
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }
        return std::min(dp[n-1], dp[n-2]);
    }

    int minCostClimbingStairs_1(std::vector<int>& cost) {
        const int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        int dp_0 = cost[0];
        int dp_1 = cost[1];

        for (int i=2; i<n; ++i) {
            int dp = cost[i] + std::min(dp_0, dp_1);
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return std::min(dp_0, dp_1);
    }
};