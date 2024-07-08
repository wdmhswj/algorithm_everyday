#include <vector>

using std::vector;

class Solution {
private:
    bool backtracking(const int& target, const vector<int>& nums, int sum, int index) {
        if (sum==target) {
            return true;
        }
        if (sum>target) {
            return false;
        }
        for(int i=index; i<nums.size(); ++i) {
            if(backtracking(target, nums, sum+nums[i], i+1))
                return true;         
        }
        return false;
    }

public:
    bool canPartition(vector<int>& nums) {
        // 求总和
        int sum=0;
        for (const int& num : nums) {
            sum+=num;
        }
        if (sum%2==1) {
            return false;
        }
        int target = sum/2;
        return backtracking(target, nums, 0, 0);

    }
    bool canPartition1(vector<int>& nums) {
        // 求总和
        int sum=0;
        for (const int& num : nums) {
            sum+=num;
        }
        if (sum%2==1) {
            return false;
        }
        int target = sum/2;
        
        vector<bool> dp(target+1, false);
        dp[0]=true;
        for (const int& num : nums) {
            for(int j=target; j>=num; --j) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
    bool canPartition2(vector<int>& nums) {
        // 求总和
        int sum=0;
        for (const int& num : nums) {
            sum+=num;
        }
        if (sum%2==1) {
            return false;
        }
        int target = sum/2;
        
        vector<int> dp(target+1, 0);
        for (const int& num : nums) {
            for(int j=target; j>=num; --j) {
                dp[j] = std::max(dp[j], dp[j-num]+num);
            }
        }
        return dp[target]==target;
    }
    bool canPartition3(vector<int>& nums) {
        // 求总和
        int sum=0;
        for (const int& num : nums) {
            sum+=num;
        }
        if (sum%2==1) {
            return false;
        }
        int target = sum/2;
        
        vector<int> dp(target+1, false);
        dp[0]=true;
        for (const int& num : nums) {
            for(int j=target; j>=num; --j) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
};