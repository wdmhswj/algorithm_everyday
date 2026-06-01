#include "../../utils/utils.h"

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        const int n = coins.size();
        if (n == 0) return -1;

        std::vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int i=1; i<=amount; ++i) {
            for (const int& coin: coins) {
                dp[i] = (i >= coin) ? std::min(dp[i], dp[i-coin]+1) : dp[i];
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};