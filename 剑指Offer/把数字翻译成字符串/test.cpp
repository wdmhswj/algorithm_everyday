#include "../../utils/utils.h"


class Solution {
public:
    int crackNumber(int ciphertext) {
        std::string num = std::to_string(ciphertext);
        const int n = num.size();
        std::vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            int cur_digit = num[i-1]-'0';
            int front_digit = num[i-2]-'0';
            
            if (front_digit*10+cur_digit>=0 && front_digit*10+cur_digit<=25 && front_digit!=0) {
                dp[i] = dp[i-1] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }

    // 优化版本
    int crackNumber1(int ciphertext) {
        std::string num = std::to_string(ciphertext);
        const int n = num.size();
        int dp_0 = 1, dp_1 = 1;
        for (int i=2; i<=n; ++i) {
            int cur_digit = num[i-1]-'0';
            int front_digit = num[i-2]-'0';
            int dp = dp_1;
            if ((cur_digit<6 && front_digit==2) || front_digit==1) {
                dp += dp_0;
            }
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return dp_1;
    }
};