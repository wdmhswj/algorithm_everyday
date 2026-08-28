#include "../../../utils/utils.h"


class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> nums_c(nums.begin(), nums.end());
        std::sort(nums_c.begin(), nums_c.end()); // 排序
        
        std::unordered_map<int, int> cnt; // value -> nums of element smaller than it
        cnt[nums_c[0]] = 0; // 手动设置
        for (int i=1; i<n; ++i) {
            if (nums_c[i] != nums_c[i-1]) { // 排序后相同数字的第一个
                cnt[nums_c[i]] = i; // 索引表示比它小的数目
            }
        }

        std::vector<int> res;
        res.reserve(n);
        for (int i=0; i<n; ++i) {
            res.push_back(cnt[nums[i]]);
        }
        return res;
    }
};