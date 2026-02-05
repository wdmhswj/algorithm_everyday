#include "../../utils/utils.h"


class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        if (k <= 0) return false; // 边界处理
        std::set<long> s;
        for (std::size_t i=0; i<nums.size(); ++i)
        {
            auto it = s.lower_bound(static_cast<long>(nums[i])-t);
            if (it!=s.end() && *it<=static_cast<long>(nums[i])+t) return true;
            s.insert(static_cast<long>(nums[i]));
            if (i>=k) s.erase(nums[i-k]);
        }
        return false;
    }
};