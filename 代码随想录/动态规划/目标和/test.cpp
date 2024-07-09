#include <iostream>
#include <vector>

using std::vector;

class Solution {
    void backtracking(const vector<int>& nums, int target, int sum, int index, int& count) {
        if (sum==target) {
            ++count;
            // return;
        }
        for(int i=index; i<nums.size() && sum+nums[i]<=target; ++i) {
            backtracking(nums, target, sum+nums[i], i+1, count);
        }
    }
public:

    // 回溯
    int findTargetSumWays(vector<int>& nums, int target) {
        // 求元素和
        int sum = 0;
        for(const int& num: nums) {
            sum+=num;
        }
        if (sum<target) {
            return 0;
        }
        if ((sum-target)%2!=0) {
            return 0;
        }
        int new_target = (sum-target)/2;
        int count=0;
        std::sort(nums.begin(), nums.end());
        backtracking(nums, new_target, 0, 0, count);
        return count;
    }

    // dp
    int findTargetSumWays1(vector<int>& nums, int target) {
        // 求元素和
        int sum = 0;
        for(const int& num: nums) {
            sum+=num;
        }
        if (sum<target) {
            return 0;
        }
        if ((sum-target)%2!=0) {
            return 0;
        }
        int new_target = (sum-target)/2;
        vector<int> dp(new_target+1, 0);
        dp[0]=1;
        for (const int& num : nums) {
            for(int j=new_target; j>=num; --j) {
                dp[j] += dp[j-num];
            }
        }
        return dp[new_target];
    }
};