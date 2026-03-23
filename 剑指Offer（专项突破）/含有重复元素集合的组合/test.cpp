#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        backtrack(res, cur, candidates, 0, 0, target);
        return res;
    }

private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& cur, const std::vector<int>& candidates, int index, int sum, int target) {
        if (sum==target) {
            res.push_back(cur);
            return;
        }
        if (sum>target) return;

        for (int i=index; i<candidates.size(); ++i) {
            if (i>index && candidates[i]==candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            backtrack(res, cur, candidates, i+1, sum+candidates[i], target);
            cur.pop_back();
        }
    }
};