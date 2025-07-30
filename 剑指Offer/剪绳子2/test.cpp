#include "../../utils/utils.h"

class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        std::vector<int> dp(bamboo_len+1, 0);
        dp[1]=1;
        for (int i=2; i<=bamboo_len; ++i)
        {
            for (int j=1; j<i; ++j)
            {
                dp[i] = std::max( {dp[i], (i-j)*j, dp[i-j]*j} );
            }
        }
        return dp[bamboo_len];
    }

    // 考虑不剪时的大小（比如总长度为3，不剪的长度3最大）
    int cuttingBamboo1(int bamboo_len) {
        std::vector<int> dp(bamboo_len+1, 0);
        for (int i=1; i<=bamboo_len; ++i)
        {
            dp[i]=i;
        }
        for (int i=2; i<=bamboo_len; ++i)
        {
            for (int j=1; j<i; ++j)
            {
                dp[i] = std::max( {dp[i], dp[i-j]*j} );
            }
        }
        return dp[bamboo_len];
    }

    int cuttingBamboo2(int bamboo_len) {
        if (bamboo_len<4) return bamboo_len-1;
        const int mod = 1e9 + 7;
        auto mpow = [&](long long a, long long n) {
            long long ans=1;
            for (; n; n/=2) {
                if (n&1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        if (bamboo_len%3 == 0) return mpow(3, bamboo_len/3);
        if (bamboo_len%3 == 1) return mpow(3, bamboo_len/3-1) * 4L % mod;
        return mpow(3, bamboo_len/3) * 2 % mod;
    }
};