#include<vector>

using std::vector;

class Solution {
private:
    void backtracking(const vector<int>& nums, vector<vector<int>>&res, vector<int>& path,vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums, res, path, used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(nums, res, path, used);
        return res;

    }
};