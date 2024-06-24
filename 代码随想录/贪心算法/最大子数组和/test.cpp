#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        
        for (int startIndex = 0; startIndex<nums.size(); ) {
            int j = startIndex;
            int count = 0;
            while (j<nums.size() && count >=0) {
                count += nums[j];
                if (count>res) {
                    res = count;
                }
                ++j;
            }
            startIndex = j;
        }
        return res;
    }

     int maxSubArray1(vector<int>& nums) {  // 只需用1个指针就行，子序列和为负数时只需使得和值为0即可
        int res = nums[0];
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            count+=nums[i];
            if (count>res) {
                res = count;
            }
            if (count<0) {
                count = 0;
            }
        }

        return res;
    }

    int maxSubArray2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i =0; i<nums.size(); ++i) {
            dp[i] = std::max(dp[i-1]+nums[i], nums[i]);         // dp[i]表示必须以nums[i]结尾的最大连续子序列之和
            if (dp[i]>res) {
                res = dp[i];
            }
        }
        return res;
    }
};


