#include "../../utils/utils.h"

class Solution {
public:
    int rob(std::vector<int>& nums) {
        const int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i=2; i<n; ++i) {
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }

    int rob_1(std::vector<int>& nums) {
        const int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        int dp_0 = nums[0];
        int dp_1 = std::max(nums[0], nums[1]);
        for (int i=2; i<n; ++i) {
            // dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
            int dp = std::max(dp_1, dp_0+nums[i]);
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return dp_1;
    }
};