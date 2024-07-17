#include <algorithm>
#include <climits>
#include <vector>
#include "../../../utils/printH.h"
using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        vector<vector<vector<int>>> dp(
            prices.size(),
            vector<vector<int>>(
                2, vector<int>(
                    3, 0
                )
            )
        );
        int max_price=0;
        for (auto& price : prices) {
            max_price=std::max(max_price, price);
        }
        dp[0][1][0]=-prices[0];
        dp[0][0][0]=0;
        dp[0][0][1]=-max_price;
        dp[0][0][2]=-max_price;
        dp[0][1][1]=-max_price;
        dp[0][1][2]=-max_price;

        for(int j=1; j<prices.size(); ++j) {
            // dp[j][0][0] = dp[j-1][0][0];
            dp[j][0][1] = std::max(dp[j-1][0][1], dp[j-1][1][0]+prices[j]);
            dp[j][0][2] = std::max(dp[j-1][0][2], dp[j-1][1][1]+prices[j]);
            dp[j][1][0] = std::max(dp[j-1][1][0], dp[j-1][0][0]-prices[j]);
            dp[j][1][1] = std::max(dp[j-1][1][1], dp[j-1][0][1]-prices[j]);
            dp[j][1][2] = std::max(dp[j-1][1][2], dp[j-1][0][2]-prices[j]);
        }
        printVector3D(dp);
        int res=std::max(dp[prices.size()-1][0][2], dp[prices.size()-1][0][1]);
        return res>=0?res:0;
    }

    // 优化版，使用滚动数组
    int maxProfit1(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        int max_price=0;
        for (auto& price : prices) {
            max_price=std::max(max_price, price);
        }
        // dp[0][1][0]=-prices[0];
        int dp_0_0=0;
        int dp_1_0=-prices[0];
        // dp[0][0][0]=0;
        // dp[0][0][1]=-max_price;
        int dp_0_1=-max_price;
        // dp[0][0][2]=-max_price;
        int dp_0_2=-max_price;
        // dp[0][1][1]=-max_price;
        int dp_1_1=-max_price;
        // dp[0][1][2]=-max_price;
        // int dp_1_2=-max_price;

        int n_dp_1_0=0;
        int n_dp_0_1=0;
        int n_dp_0_2=0;
        int n_dp_1_1=0;
        // int n_dp_1_2=0;


        for(int j=1; j<prices.size(); ++j) {
            // dp[j][0][1] = std::max(dp[j-1][0][1], dp[j-1][1][0]+prices[j]);
            n_dp_0_1 = std::max(dp_0_1, dp_1_0+prices[j]);
            // dp[j][0][2] = std::max(dp[j-1][0][2], dp[j-1][1][1]+prices[j]);
            n_dp_0_2 = std::max(dp_0_2, dp_1_1+prices[j]);
            // dp[j][1][0] = std::max(dp[j-1][1][0], dp[j-1][0][0]-prices[j]);
            n_dp_1_0 = std::max(dp_1_0, dp_0_0-prices[j]);
            // dp[j][1][1] = std::max(dp[j-1][1][1], dp[j-1][0][1]-prices[j]);
            n_dp_1_1 = std::max(dp_1_1, dp_0_1-prices[j]);
            // dp[j][1][2] = std::max(dp[j-1][1][2], dp[j-1][0][2]-prices[j]);
            // n_dp_1_2 = std::max(dp_1_2, dp_0_2+prices[j]);

            dp_0_1=n_dp_0_1;
            dp_0_2=n_dp_0_2;
            dp_1_0=n_dp_1_0;
            dp_1_1=n_dp_1_1;
        }
        // printVector3D(dp);
        int res=std::max(dp_0_2, dp_0_1);
        return res>=0?res:0;
    }
    // 优化版v2，减少局部变量
    int maxProfit2(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }

        int max_price=0;
        for (auto& price : prices) {
            max_price=std::max(max_price, price);
        }
        // dp[0][1][0]=-prices[0];
        int dp_0_0=0;
        int dp_1_0=-prices[0];
        // dp[0][0][0]=0;
        // dp[0][0][1]=-max_price;
        int dp_0_1=-max_price;
        // dp[0][0][2]=-max_price;
        int dp_0_2=-max_price;
        // dp[0][1][1]=-max_price;
        int dp_1_1=-max_price;
        // dp[0][1][2]=-max_price;
        // int dp_1_2=-max_price;

        for(int j=1; j<prices.size(); ++j) {
            dp_0_2 = std::max(dp_0_2, dp_1_1+prices[j]);
            dp_1_1 = std::max(dp_1_1, dp_0_1-prices[j]);
            dp_0_1 = std::max(dp_0_1, dp_1_0+prices[j]);
            dp_1_0 = std::max(dp_1_0, dp_0_0-prices[j]);
        }
        // printVector3D(dp);
        int res=std::max(dp_0_2, dp_0_1);
        return res>=0?res:0;
    }
};

int main(){
    Solution solution;
    vector<int> prices={7,6,4,3,1};
    vector<int> prices1={1,2,3,4,5};
    std::cout<<solution.maxProfit1(prices);
}