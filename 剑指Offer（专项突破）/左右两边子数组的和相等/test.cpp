#include "../../utils/utils.h"
class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        for (const int& e: nums)
        {
            sum += e;
        }
        int leftSum = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (sum - 2*leftSum - nums[i] == 0)
            {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};