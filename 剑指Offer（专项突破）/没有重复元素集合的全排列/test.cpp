#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::vector<int> used(nums.size(), false);
        backtrack(res, cur, used, nums);
        return res;
    }
private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& cur, std::vector<int>& used, const std::vector<int>& nums) {
        if (cur.size()==nums.size()) {
            res.emplace_back(cur);
            return;
        }

        for (int i=0; i<nums.size(); ++i) {
            if (used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            backtrack(res, cur, used, nums);
            used[i] = false;
            cur.pop_back();
        }
    }
};