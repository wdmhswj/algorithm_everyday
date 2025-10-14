#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> rt(n+1, 0);
        for (int i = 0; i <= n; i++)
        {
            int j = i;
            while (j)
            {
                if (j&1) ++rt[i];
                j >>= 1;
            }
        }
        return rt;  
    }

    std::vector<int> countBits1(int n) {
        
        std::vector<int> dp(n+1, 0);
        if (n==0) return dp;
        dp[1] = 1;

        for (int i=2; i<=n; ++i)
        {
            if (i%2==0)
            {
                dp[i] = dp[i/2];
            } else 
            {
                dp[i] = dp[i/2] + 1;
            }
        }
        return dp;
    }

    std::vector<int> countBits2(int n) {
        
        std::vector<int> dp(n+1, 0);
        if (n==0) return dp;
        dp[1] = 1;

        for (int i=2; i<=n; ++i)
        {
            dp[i] = dp[i&(i-1)]+1;
        }
        return dp;
    }
};