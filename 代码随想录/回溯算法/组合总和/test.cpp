#include <algorithm>
#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>>res;
    vector<int> path;
    void backtracking(const vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum==target) {
            res.push_back(path);
            return;
        }
        if (sum>target) {
            return;
        }
        
        for (int i=startIndex; i<candidates.size() && sum+candidates[i]<=target; i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return {};
        }
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};