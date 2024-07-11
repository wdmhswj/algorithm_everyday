#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (coins.empty()) {
            return 0;
        }

        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for(int i=0; i<coins.size(); ++i){
            for(int j=coins[i]; j<=amount; ++j) {
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }

    // 错误for循环遍历顺序
    int change1(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (coins.empty()) {
            return 0;
        }

        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for (int j = 0; j <= amount; j++) { // 遍历背包容量
            for (int i = 0; i < coins.size(); i++) { // 遍历物品
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                    std::cout<<"dp["<<j<<"] = "<<dp[j]<<"\t"<<"dp[j-coins[i]]="<<"dp["<<j-coins[i]<<"]="<<dp[j-coins[i]]<<std::endl;
                }
            }
        }
        return dp[amount];
    }
};

int main(){

    Solution s;

    vector<int> coins({1, 5});
    s.change1(6, coins);
}