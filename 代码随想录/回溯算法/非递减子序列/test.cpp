#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
private:
    bool findTarget(const vector<int>& nums, int beginIndex, int endIndex, int target) {
        for (int i=beginIndex; i<endIndex; ++i) {
            if (nums[i]==target) {
                return true;
            }
        }
        return false;
    }
    void backtracking(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int startIndex) {
        if (path.size()>=2) {
            res.push_back(path);
        }
        std::unordered_set<int> used;
        for (int i=startIndex; i<nums.size(); ++i) {
            // 7,6,7：前面的7不在path中但nums之前有7
            // 4,6,7,7
            if (used.find(nums[i])!=used.end()) {   // 同一父节点的同层节点使用过了
                continue;
            }
            // 不符合非递减
            if (!path.empty() && nums[i]<path.back()) {
                continue;
            }
            path.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(nums, res, path, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty() || nums.size()<=1) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        // vector<bool> used(nums.size(), false);
        // std::unordered_map<int, bool> used(false);
        backtracking(nums, res, path, 0);
        return res;
    }
};