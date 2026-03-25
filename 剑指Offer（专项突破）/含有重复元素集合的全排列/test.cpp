#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtrack(res, cur, used, nums);
        return res;
    }
private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& cur, std::vector<bool>& used, const std::vector<int>& nums) {
        if (cur.size()==nums.size()) {
            res.emplace_back(cur);
            return;
        }

        for (int i=0; i<nums.size(); ++i) {
            if (used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

            cur.push_back(nums[i]);
            used[i] = true;
            backtrack(res, cur, used, nums);
            used[i] = false;
            cur.pop_back();
        }

    }
};