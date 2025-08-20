#include "../../utils/utils.h"


class Solution {
public:

    // 时间复杂度 O(m*n)，空间复杂度 O(m*n)
    int jewelleryValue(std::vector<std::vector<int>>& frame) {
        const int m = frame.size();
        if (m==0) return 0;
        const int n = frame[0].size();
        if (n==0) return 0;

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                dp[i][j] = frame[i-1][j-1] + std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }

    // 优化版本：时间复杂度 O(m*n)，空间复杂度 O(n)
    int jewelleryValue(std::vector<std::vector<int>>& frame) {
        const int m = frame.size();
        if (m==0) return 0;
        const int n = frame[0].size();
        if (n==0) return 0;

        std::vector<int> dp(n+1, 0);
        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                dp[j] = frame[i-1][j-1] + std::max(dp[j], dp[j-1]);
            }
        }
        return dp[n];
    }
};