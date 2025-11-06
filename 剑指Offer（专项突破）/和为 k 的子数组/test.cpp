#include "../../utils/utils.h"


class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;

        int ret = 0, prefix_sum = 0;
        for (const int& e: nums)
        {
            prefix_sum += e;    // 更新前缀和
            ret += cnt[prefix_sum-k];   // 前缀和为prefix_sum与前缀和为prefix_sum-k的数组之差即为所求
            ++cnt[prefix_sum];
        }
        return ret;
    }
};