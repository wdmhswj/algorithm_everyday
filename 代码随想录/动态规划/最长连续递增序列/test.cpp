#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()<=1) {
            return nums.size();
        }

        vector<int> dp(nums.size(), 1);
        int res=1;
        for(int i=1; i<nums.size(); ++i) {
           if (nums[i-1]<nums[i]) {
                dp[i]=dp[i-1]+1;
            }
            res = std::max(dp[i], res);
        }
        return res;
    }
    // 法2：贪心算法
    int findLengthOfLCIS1(vector<int>& nums) {
        if (nums.size()<=1) {
            return nums.size();
        }

        int count = 1;
        int res = 0;
        for(int i=1; i<nums.size(); ++i) {
            for(int i=1; i<nums.size(); ++i) {
            if (nums[i-1]<nums[i]) {
                ++count;
            } else {
                count=1;
            }
            if(res<count)   res=count;
        }
        }
        return res;
    }
};