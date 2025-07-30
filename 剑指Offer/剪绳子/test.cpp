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
        if (bamboo_len%3 == 0) return pow(3, bamboo_len/3);
        if (bamboo_len%3 == 1) return pow(3, bamboo_len/3-1)*4;
        return pow(3, bamboo_len/3)*2;
    }
};