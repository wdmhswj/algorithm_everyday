#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[1][0]=std::max(dp[0][0], dp[0][1]+prices[1]);
        dp[1][1]=std::max(dp[0][1], -prices[1]);

        for(int j=2; j<prices.size(); ++j) {
            dp[j][0] = std::max(dp[j-1][0], dp[j-1][1]+prices[j]);
            dp[j][1] = std::max(dp[j-1][1], dp[j-2][0]-prices[j]);
        }
        return dp[prices.size()-1][0];
    }
    
    // 优化版
    int maxProfit1(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        // vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // dp[0][0]=0;
        // dp[0][1]=-prices[0];
        // dp[1][0]=std::max(dp[0][0], dp[0][1]+prices[1]);
        // dp[1][1]=std::max(dp[0][1], -prices[1]);
        int dp_i_0=0;
        int dp_i_1=-prices[0];
        int dp_pre_0 = 0;
         

        for(int j=1; j<prices.size(); ++j) {
            int tmp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1+prices[j]);
            dp_i_1 = std::max(dp_i_1, dp_pre_0-prices[j]);
            dp_pre_0 = tmp;
        }
        return dp_i_0;
    }
};