#include <algorithm>
#include <vector>

using std::vector;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }

        vector<int> dp(amount+1, amount+1); // 初始化为一个很大的值
        dp[0] = 0;
        for(int j=0; j<=amount; ++j) {
            for(int i=0; i<coins.size(); ++i) {
                if (j>=coins[i]) {
                    dp[j] = std::min(dp[j-coins[i]]+1, dp[j]);
                }
            }
        }
        return dp[amount]==amount+1 ? -1: dp[amount];
    }
    int coinChange1(vector<int>& coins, int amount) {
        if (amount==0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }

        vector<int> dp(amount+1, amount+1); // 初始化为一个很大的值
        dp[0] = 0;
        for(const int& coin: coins) {
            for(int j=coin; j<=amount; ++j) {
                if (dp[j-coin]!=amount+1) {
                    dp[j] = std::min(dp[j-coin]+1, dp[j]);
                }
            }
        }
        return dp[amount]==amount+1 ? -1: dp[amount];
    }
};