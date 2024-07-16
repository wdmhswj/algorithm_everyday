#include <vector>

using std::vector;

class Solution {
public:

    // 法1：贪心算法
    int maxProfit(vector<int>& prices) {
         if (prices.size()<=1) {
            return 0;
        }
        int res = 0;
        for(int i=1; i<prices.size(); ++i) {
            if (prices[i]>prices[i-1]) {
                res += (prices[i]-prices[i-1]);
            }
        }
        return res;
    }

    // 法2：dp
    int maxProfit1(vector<int>& prices){
         if(prices.empty() || prices.size()==1) {
            return 0;
        }
        int dp_0=0;
        int dp_1=-prices[0];

        for (int i=1; i<prices.size(); ++i) {
            int new_dp_1= std::max(dp_1, dp_0-prices[i]);
            int new_dp_0 = std::max(dp_0, dp_1+prices[i]);
            dp_1=new_dp_1;
            dp_0=new_dp_0;
        }
        return dp_0;
    }
    int maxProfit1_1(vector<int>& prices){
         if(prices.empty() || prices.size()==1) {
            return 0;
        }
        int dp_0=0;
        int dp_1=-prices[0];
        int new_dp_1=0;
        int new_dp_0=0;
        for (int i=1; i<prices.size(); ++i) {
            new_dp_1= std::max(dp_1, dp_0-prices[i]);
            new_dp_0 = std::max(dp_0, dp_1+prices[i]);
            dp_1=new_dp_1;
            dp_0=new_dp_0;
        }
        return dp_0;
    }
};