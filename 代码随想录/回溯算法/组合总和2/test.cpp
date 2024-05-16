#include <vector>
#include <algorithm>
using std::vector;


class Solution {
private:
    vector<vector<int>>res;
    vector<int> path;
    void backtracking(const vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum==target) {
            res.push_back(path);
            return;
        }
        if (sum>target) {
            return;
        }
        
        for (int i=startIndex; i<candidates.size() && sum+candidates[i]<=target; i++) {
            if (i>0 && candidates[i-1]==candidates[i] && used[i-1]==false) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i]=true;
            backtracking(candidates, target, sum+candidates[i], i+1, used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return {};
        }
        std::sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};