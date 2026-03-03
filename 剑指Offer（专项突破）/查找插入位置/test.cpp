#include "../../utils/utils.h"

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        size_t l=0, r=nums.size();
        while (l<r) {
            size_t mid = l + (r-l)/2;
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};