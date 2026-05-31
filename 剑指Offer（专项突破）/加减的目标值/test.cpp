#include "../../utils/utils.h"

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return 0;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > sum) return 0;
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(2 * sum + 1, 0));
        dp[0][nums[0] + sum] += 1;
        dp[0][-nums[0] + sum] += 1;
        for (int i = 1; i < n; ++i) {
            for (int j = -sum; j <= sum; ++j) {
                dp[i][j + sum] = (j - nums[i] >= -sum ? dp[i-1][j - nums[i] + sum] : 0) + 
                                 (j + nums[i] <= sum ? dp[i-1][j + nums[i] + sum] : 0);
            }
        }
        return dp[n-1][target + sum];
    }

    int findTargetSumWays_1(std::vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return 0;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > sum) return 0;
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) return 0;
        int neg = diff / 2;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= neg; ++j) {
                dp[i][j] = dp[i-1][j] + ( j>=nums[i-1] ? dp[i-1][j-nums[i-1]] : 0 );
            }
        }
        return dp[n][neg];
    }

    int findTargetSumWays_2(std::vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return 0;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > sum) return 0;
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) return 0;
        int neg = diff / 2;
        // std::vector<std::vector<int>> dp(n+1, std::vector<int>(neg + 1, 0));
        std::vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = neg; j >= nums[i-1]; --j) {
                dp[j] = dp[j] + dp[j-nums[i-1]];
            }
        }
        return dp[neg];
    }
};