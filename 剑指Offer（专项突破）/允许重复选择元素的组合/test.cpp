#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(res, cur, candidates, 0, target, 0);
        return res;
    }
private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& cur, const std::vector<int>& candidates, int sum, int target, int index) {
        if (sum==target) {
            res.push_back(cur);
            return;
        }
        if (sum>target) return;

        for (int i=index; i<candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            backtrack(res, cur, candidates, sum+candidates[i], target, i);
            cur.pop_back();
        }
    }
};