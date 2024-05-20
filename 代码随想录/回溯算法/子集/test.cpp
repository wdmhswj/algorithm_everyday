#include <vector>

using std::vector;
class Solution {
private:
    void backtracking(const vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& res) {
        if (startIndex>=nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i=startIndex; i<=nums.size(); ++i){
            if (i==nums.size()) {   // 不添加元素，直接结束
                res.push_back(path);
                break;
            }else {
                path.push_back(nums[i]);
                backtracking(nums, i+1, path, res);
                path.pop_back();
            }
        }
    }
     void backtracking_1(const vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        if (startIndex>=nums.size()) {
            return;
        }
        for(int i=startIndex; i<nums.size(); ++i){
            path.push_back(nums[i]);
            backtracking(nums, i+1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        backtracking(nums, 0, path, res);
        return res;
    }
};