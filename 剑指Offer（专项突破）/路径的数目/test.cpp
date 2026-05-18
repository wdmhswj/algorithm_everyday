#include "../../utils/utils.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int i=0; i < m; ++i) {
            dp[i][0] = 1; // 第一列的路径数量为1
        }

        for (int j=0; j < n; ++j) {
            dp[0][j] = 1; // 第一行的路径数量为1
        }

        for (int i=1; i < m; ++i) {
            for (int j=1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // 当前路径数量等于上方和左方路径数量之和
            }
        }

        return dp[m-1][n-1]; // 返回右下角的路径数量
    }


    int uniquePaths_1(int m, int n) {
        if (m < n) return uniquePaths_1(n, m); // 保持 m >= n 以优化空间复杂度
        std::vector<int> dp(n, 1); // 第一行的路径数量为1

        for (int i=1; i < m; ++i) {
            for (int j=1; j < n; ++j) {
                dp[j] += dp[j-1]; // 当前路径数量等于上方和左方路径数量之和
            }
        }

        return dp[n-1]; // 返回右下角的路径数量
    }
};