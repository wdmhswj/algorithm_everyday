#include "../../utils/utils.h"

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& costs) {
        const int n = costs.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int i=1; i<n; ++i) {
            for (int j=0; j<3; ++j) {
                dp[i][j] = costs[i][j] + std::min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        return std::min(dp[n-1][0], std::min(dp[n-1][1], dp[n-1][2]));
    }


    int minCost_1(std::vector<std::vector<int>>& costs) {
        const int n = costs.size();
        // std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
        // dp[0][0] = costs[0][0];
        int dp_0 = costs[0][0];
        // dp[0][1] = costs[0][1];
        int dp_1 = costs[0][1];
        // dp[0][2] = costs[0][2];
        int dp_2 = costs[0][2];
        int a=0, b=0, c=0;

        for (int i=1; i<n; ++i) {
            a = dp_0;
            b = dp_1;
            c = dp_2;
            for (int j=0; j<3; ++j) {
                // dp[i][j] = costs[i][j] + std::min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
            dp_0 = costs[i][0] + std::min(b, c);
            dp_1 = costs[i][1] + std::min(a, c);
            dp_2 = costs[i][2] + std::min(b, a);
        }
        return std::min(dp_0, std::min(dp_1, dp_2));
    }
};