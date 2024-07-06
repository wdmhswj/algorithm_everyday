#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();    // 楼梯数
        if (n==0||n==1) {
            return 0;
        }
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=0;
        for (int i=2; i<=n; ++i) {
            dp[i]=std::min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];

    }
};