#include "../../utils/utils.h"

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int ret = INT_MAX;
        const int n = nums.size();
        int sum = 0;
        for (int l=0, r=0; r<n; ++r)
        {
            sum += nums[r];
            while (sum>=target)
            {
                ret = std::min(ret, r-l+1);
                sum -= nums[l];
                ++l;
            }
        }
        return ret==INT_MAX ? 0 : ret;
    }
};