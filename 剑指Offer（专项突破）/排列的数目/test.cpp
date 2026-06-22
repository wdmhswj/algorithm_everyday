#include "../../utils/utils.h"


class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for (int i=1; i<=target; ++i) {
            for (const int& num: nums) {
                if (i>=num) {
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};