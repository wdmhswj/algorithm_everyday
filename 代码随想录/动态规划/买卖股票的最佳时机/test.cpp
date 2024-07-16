#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:

    // 法1：贪心算法
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }

        int min=prices[0];
        int res=0;
        for (int i=1; i<prices.size(); ++i) {
            min=std::min(min, prices[i]);
            res=std::max(res, prices[i]-min);
        }
        return res;
    }

    // 法2：dp
    int maxProfit1(vector<int>& prices) {
        if(prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for (int i=1; i<prices.size(); ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = std::max(dp[i-1][1], -prices[i]);
        }
        return dp[prices.size()-1][0];

    }
    // 法2：dp（优化版）
    int maxProfit2(vector<int>& prices) {
        if(prices.empty() || prices.size()==1) {
            return 0;
        }
        int dp_0=0;
        int dp_1=-prices[0];

        for (int i=1; i<prices.size(); ++i) {
            int new_dp_1= std::max(dp_1, -prices[i]);
            int new_dp_0 = std::max(dp_0, dp_1+prices[i]);
            dp_1=new_dp_1;
            dp_0=new_dp_0;
        }
        return dp_0;
    }
};