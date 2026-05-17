#include "../../utils/utils.h"

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0; // 如果 t 的长度大于 s 的长度，则 t 不可能是 s 的子序列
        std::vector<std::vector<unsigned long long>> dp(m + 1, std::vector<unsigned long long>(n + 1, 0));

        for (int i=0; i <= m; ++i) {
            dp[i][0] = 1; // 空字符串是任何字符串的子序列
        }

        for (int i=1; i <= m; ++i) {
            for (int j=1; j <= n; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }

    int numDistinct_1(std::string s, std::string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0; // 如果 t 的长度大于 s 的长度，则 t 不可能是 s 的子序列
        std::vector<unsigned long long> dp(n + 1, 0);

        dp[0] = 1; // 空字符串是任何字符串的子序列

        for (int i=1; i <= m; ++i) {
            for (int j=n; j >= 1; --j) {
                if (s[i-1] == t[j-1]) {
                    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    dp[j] += dp[j-1];
                } else {
                    // dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n];
    }
};