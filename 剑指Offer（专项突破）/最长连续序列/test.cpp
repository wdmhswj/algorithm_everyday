#include "../../utils/utils.h"

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return n;
        std::sort(nums.begin(), nums.end());

        int res = 1;
        int len = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1]+1) {
                ++len;
                res = std::max(res, len);
            } else {
                len = 1;
            }
        }
        return res;
    }

    int longestConsecutive(std::vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return n;
        std::unordered_set<int> hash(nums.begin(), nums.end());
        int res = 1;
        for (int num: nums) {
            if (!hash.count(num-1)) {
                int end = num+1;
                while (hash.count(end)) {
                    ++end;
                }
                res = std::max(res, end-num);
            }
        }
        return res;
    }
};