#include "../../utils/utils.h"



class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& price, int target) {
        const int n = price.size();
        if (n<2) return {};
        int l = 0, r = n-1;
        while (l<n)
        {
            int sum = price[l] + price[r];
            if (sum == target)
                return {price[l], price[r]};
            else if (sum < target)
                ++l;
            else
                --r;
        }
        return {};
    }
};