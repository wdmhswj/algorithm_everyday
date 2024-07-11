#include <climits>
#include <vector>

using std::vector;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target==0) {
            return 1;
        }
        if (nums.empty()) {
            return 0;
        }

        vector<unsigned long long> dp(target+1, 0);
        dp[0]=1;

        for(int j=0; j<=target; ++j) {
            for(int i=0; i<nums.size(); ++i) {
                if (j>=nums[i]) {
                    dp[j]+=dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
    int combinationSum4_1(vector<int>& nums, int target) {
        if (target==0) {
            return 1;
        }
        if (nums.empty()) {
            return 0;
        }

        vector<int> dp(target+1, 0);
        dp[0]=1;

        for(int j=0; j<=target; ++j) {
            for(int i=0; i<nums.size(); ++i) {
                if (j>=nums[i] && dp[j-nums[i]]<INT_MAX-dp[j] ) {
                    dp[j]+=dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};