#include "../../utils/utils.h"

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        const int m = text1.size();
        const int n = text2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    int longestCommonSubsequence_1(std::string text1, std::string text2) {
        const int m = text1.size();
        const int n = text2.size();
        // 让 n 为较小的长度，减少空间
        if (m < n) {
            return longestCommonSubsequence(text2, text1);
        }

        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            int prev = 0; // 代表 dp[i-1][0]，初始为 0
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // 记录当前 dp[j] 作为下一轮的左上角
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;      // prev 就是 dp[i-1][j-1]
                } else {
                    dp[j] = std::max(dp[j], dp[j - 1]); // dp[j] 是上方的值，dp[j-1] 是左侧的值
                }
                prev = temp; // 更新左上角
            }
        }
        return dp[n];
    }
};