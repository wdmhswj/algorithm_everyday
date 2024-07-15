#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size()==1) {
            return nums[0];
        }
        if (nums.size()==2) {
            return std::max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size()-1, 0);
        dp[0]=nums[0];
        dp[1]=std::max(nums[0], nums[1]);
        for(int j=2; j<nums.size()-1; ++j) {
            dp[j] = std::max(dp[j-1], dp[j-2]+nums[j]);
        }
        int res1=dp[nums.size()-2];

        dp.assign(dp.size(), 0);
        dp[0] = nums[1];
        dp[1]=std::max(nums[1], nums[2]);
        for(int j=2; j<nums.size()-1; ++j) {
            dp[j] = std::max(dp[j-1], dp[j-2]+nums[j+1]);
        }
        int res2=dp[nums.size()-2];
        return std::max(res1, res2);
    }
};