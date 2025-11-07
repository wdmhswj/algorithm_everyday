#include "../../utils/utils.h"
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> d; // 前缀和第一次出现的位置
        d[0] = -1;
        int ret = 0, sum = 0;
        const int n = nums.size();
        for (int i=0; i<n; ++i)
        {
            sum += nums[i] ? 1 : -1;
            auto it = d.find(sum);
            if (it != d.end()) {
                ret = std::max(ret, i-it->second);
            } else {
                d[sum] = i;
            }
        }
        return ret;
    }
};