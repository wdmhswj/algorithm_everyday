#include "../../utils/utils.h"


class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        int ret = 0;
        const int n = nums.size();
        long long int product = 1;
        for (int i=0, j=0; j<n; ++j)
        {
            product *= nums[j];
            while (product>=k && i<=j)
            {
                product /= nums[i];
                ++i;
            }
            ret += (j-i+1);
        }
        return ret;
    }
};