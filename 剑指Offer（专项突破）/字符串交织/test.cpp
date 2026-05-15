#include "../../utils/utils.h"


class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        const int m = s1.size();
        const int n = s2.size();
        const int l = s3.size();
        if (m + n != l) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int i=0; i<=m; ++i) {
            for (int j=0; j<=n; ++j) {
                int k = i + j - 1; // s3 的索引
                if (i > 0 && s1[i-1] == s3[k]) {
                    dp[i][j] = dp[i-1][j] || dp[i][j];
                    std::cout << "dp[" << i << "][" << j << "] = dp[" << i-1 << "][" << j << "] = " << dp[i][j];
                    std::cout << s1[i-1] << " == " << s3[k] << std::endl;
                }
                if (j > 0 && s2[j-1] == s3[k]) {
                    dp[i][j] = dp[i][j-1] || dp[i][j];
                    std::cout<< "dp[" << i << "][" << j << "] = dp[" << i << "][" << j-1 << "] = " << dp[i][j];
                    std::cout << s2[j-1] << " == " << s3[k] << std::endl;
                }
            }
        }
        return dp[m][n];
    }


    bool isInterleave_1(std::string s1, std::string s2, std::string s3) {
        const int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) return false;

        std::vector<bool> dp(n + 1, false);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else {
                    int k = i + j - 1;
                    bool from_s1 = (i > 0 && dp[j] && s1[i-1] == s3[k]);
                    bool from_s2 = (j > 0 && dp[j-1] && s2[j-1] == s3[k]);
                    dp[j] = from_s1 || from_s2;
                }
            }
        }
        return dp[n];
    }

};

int main() {
    Solution s;
    std::string s1 = "ab", s2 = "bc", s3 = "babc";
    std::cout << s.isInterleave_1(s1, s2, s3) << std::endl; // true


    return 0;
}