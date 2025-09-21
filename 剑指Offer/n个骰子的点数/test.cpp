#include "../../utils/utils.h"


class Solution {
public:
    std::vector<double> statisticsProbability(int num) {
        std::vector<std::vector<int>> dp(num+1, std::vector<int>(6*num+1));
        for (int j=1; j<=6; ++j)
        {
            dp[1][j] = 1;
        }
        for (int i=2; i<=num; ++i)
        {
            for (int j=i; j<=6*i; ++j)
            {
                for (int k=1; k<=6; ++k)
                {
                    if (j>=k)
                    {
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
            }
        }
        double divisor = std::pow(6, num);
        std::vector<double> rt;
        for (int j=num; j<=6*num; ++j)
        {
            rt.push_back(dp[num][j]/divisor);
        }
        return rt;
    }

    std::vector<double> statisticsProbability1(int num) {
        std::vector<int> dp(6*num+1);
        for (int j=1; j<=6; ++j)
        {
            dp[j] = 1;
        }
        for (int i=2; i<=num; ++i)
        {
            for (int j=6*i; j>=i; --j)
            {
                dp[j] = 0;
                for (int k=1; k<=6 && j-k>=i-1; ++k)
                {    
                    dp[j] += dp[j-k];
                }
            }
        }
        double divisor = std::pow(6, num);
        std::vector<double> rt;
        for (int j=num; j<=6*num; ++j)
        {
            rt.push_back(dp[j]/divisor);
        }
        return rt;
    }
};