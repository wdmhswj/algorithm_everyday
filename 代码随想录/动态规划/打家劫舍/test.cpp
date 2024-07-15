#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int j=2; j<=nums.size(); ++j) {
            dp[j] = std::max(dp[j-1], dp[j-2]+nums[j-1]);
        }
        return dp[nums.size()];
    }
};