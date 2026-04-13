#include "../../utils/utils.h"

class Solution {
public:
    int rob(std::vector<int>& nums) {
        const int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        return std::max(_rob(nums, 0, n-2), _rob(nums, 1, n-1));
    }

private:
    int _rob(std::vector<int>& nums, int l, int r) {
        if (l==r) return nums[l];
        int dp_0 = nums[l];
        int dp_1 = std::max(nums[l], nums[l+1]);
        for (int i=l+2; i<=r; ++i) {
            int dp = std::max(dp_1, dp_0+nums[i]);
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return dp_1;
    }
};