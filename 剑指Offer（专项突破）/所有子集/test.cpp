#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        backtrack(ret, cur, nums, 0);
        return ret;
    }

    std::vector<std::vector<int>> subsets_1(std::vector<int>& nums) {
        const int n = nums.size();
        int total = 1<<n;
        std::vector<std::vector<int>> ret;

        for (int mask=0; mask<total; ++mask) {
            std::vector<int> subset;
            for (int i=0; i<n; ++i) {
                if (mask & (1<<i)) {
                    subset.push_back(nums[i]);
                }
            }
            ret.push_back(subset);
        }
        return ret;
    }

private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& cur, const std::vector<int>& nums, int index) {
        res.push_back(cur);

        for (int i=index; i<nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(res, cur, nums, i+1);
            cur.pop_back();
        }
    }
};