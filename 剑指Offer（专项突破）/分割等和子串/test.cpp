#include "../../utils/utils.h"

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int max_num = *std::max_element(nums.begin(), nums.end());
        if (max_num > target) return false;
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(target + 1, false));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }

    bool canPartition_1(std::vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int max_num = *std::max_element(nums.begin(), nums.end());
        if (max_num > target) return false;
        // std::vector<std::vector<bool>> dp(n, std::vector<bool>(target + 1, false));
        std::vector<bool> dp(target+1, false);

        dp[0] = true;
        dp[nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};