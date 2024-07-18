#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1, 0));

        // dp数组初始化
        // dp[0][0]=0;
        // dp[0][1]=-prices[0];
        // dp[0][2]=0;
        for(int i=0; i<k;++i) {
            dp[0][2*i+1]=-prices[0];
        }

        for(int i=1; i<prices.size(); ++i) {
            for(int j=0; j<k; ++j) {
                dp[i][2*j+1] = std::max(dp[i-1][2*j+1], dp[i-1][2*j]-prices[i]);
                dp[i][2*j+2] = std::max(dp[i-1][2*j+2], dp[i-1][2*j+1]+prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }

    // 优化版
    int maxProfit1(int k, vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<int> dp(2*k+1, 0);

        for(int i=0; i<k;++i) {
            dp[2*i+1]=-prices[0];
        }

        for(int i=1; i<prices.size(); ++i) {
            for(int j=0; j<k; ++j) {
                
                dp[2*j+2] = std::max(dp[2*j+2], dp[2*j+1]+prices[i]);
                dp[2*j+1] = std::max(dp[2*j+1], dp[2*j]-prices[i]);
            }
        }
        return dp[2*k];
    }
};