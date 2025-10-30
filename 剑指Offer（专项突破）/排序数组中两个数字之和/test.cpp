#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l<r)
        {
            int sum = numbers[l]+numbers[r];
            if (sum < target)
            {
                ++l;
            } else if (sum > target)
            {
                --r;
            } else {
                return {l, r};
            }
        }
        return {-1, -1};
    }
};