#include <algorithm>
#include <vector>
using std::vector;


class Solution {
private:
    void backtracking(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int startIndex, vector<bool>& used) {
        
        res.push_back(path);    // 求子集，path的过程量也有效
        
        for(int i=startIndex; i<nums.size(); i++) {
             if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) {
               continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums, res, path, i+1, used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        // 排序
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(nums, res, path, 0, used);
        return res;

    }
};