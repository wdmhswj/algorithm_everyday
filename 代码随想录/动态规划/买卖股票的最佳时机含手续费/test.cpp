#include <algorithm>
#include<vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for(int i=1; i<prices.size(); ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[prices.size()-1][0]>0?dp[prices.size()-1][0]:0;
    }

    // 优化版（使用滚动数组）
    int maxProfit1(vector<int>& prices, int fee) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        
        int dp_i_0=0;
        int dp_i_1=-prices[0];
        int n_dp_i_0=0;
        int n_dp_i_1=0;

        for(int i=1; i<prices.size(); ++i) {
            n_dp_i_0 = std::max(dp_i_0, dp_i_1+prices[i]-fee);
            n_dp_i_1= std::max(dp_i_1, dp_i_0-prices[i]);
            dp_i_0=n_dp_i_0;
            dp_i_1=n_dp_i_1;
        }
        return dp_i_0>0?dp_i_0:0;
    }

    // 贪心算法
    int maxProfit2(vector<int>& prices, int fee) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        int min_price=prices[0]+fee;
        int profit=0;
        for(int i=1; i<prices.size(); ++i) {
            if (prices[i]+fee<min_price) {
                min_price=prices[i]+fee;
            } else if (prices[i]>min_price) {
                profit+=prices[i]-min_price;
                min_price=prices[i];
            }
        }
        return profit>0?profit:0;
    }
};