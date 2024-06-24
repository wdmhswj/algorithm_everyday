#include <algorithm>
#include <cstring>
#include <vector>

using std::vector;

// 法1（不正确）
class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> maxSubSequence(nums.size(), {0, 0, 0}); // size, last one, go or down
        for (int i=0; i<nums.size(); i++) {
            if (i==0) { // 第一个特殊处理
                maxSubSequence[0][0]=1;
                maxSubSequence[0][1]=0;
                maxSubSequence[0][2]=0;
            
                continue;
            }
            if(i==1) {
                if (nums[1]>nums[0]) {
                    maxSubSequence[1][0]=2;
                    maxSubSequence[1][1]=1;
                    maxSubSequence[1][2]=1;
                }else if (nums[1]<nums[0]) {
                    maxSubSequence[1][0]=2;
                    maxSubSequence[1][1]=1;
                    maxSubSequence[1][2]=-1;
                } else {
                    maxSubSequence[1][0]=1;
                    maxSubSequence[1][1]=0;
                    maxSubSequence[1][2]=0;
                }
                continue;
            }
            if (maxSubSequence[i-1][2]==0) {
                if (nums[i]>nums[maxSubSequence[i-1][1]]) {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0]+1;
                    maxSubSequence[i][1]=i;
                    maxSubSequence[i][2]=1;
                } else if(nums[i]<nums[maxSubSequence[i-1][1]]){
                    maxSubSequence[i][0]=maxSubSequence[i-1][0]+1;
                    maxSubSequence[i][1]=i;
                    maxSubSequence[i][2]=-1;
                } else {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0];
                    maxSubSequence[i][1]=maxSubSequence[i-1][1];
                    maxSubSequence[i][2]=0;
                }
            } else if (maxSubSequence[i-1][2]==1) {
                if (nums[i]>=nums[maxSubSequence[i-1][1]]) {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0];
                    maxSubSequence[i][1]=maxSubSequence[i-1][1];
                    maxSubSequence[i][2]=1;
                } else {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0]+1;
                    maxSubSequence[i][1]=i;
                    maxSubSequence[i][2]=-1;
                }
            } else {
                if (nums[i]<=nums[maxSubSequence[i-1][1]]) {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0];
                    maxSubSequence[i][1]=maxSubSequence[i-1][1];
                    maxSubSequence[i][2]=-1;
                } else {
                    maxSubSequence[i][0]=maxSubSequence[i-1][0]+1;
                    maxSubSequence[i][1]=i;
                    maxSubSequence[i][2]=1;
            }

        }
        
    }
    return maxSubSequence[nums.size()-1][0];
    }
};

// 法2 贪心算法
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<=1) {
            return nums.size();
        }
        int preDiff = 0;
        int curDiff = 0;
        int res = 1;    // 从1开始，2个不同的数即为摆动序列
        for (int i=0; i<nums.size()-1; ++i) {
            curDiff = nums[i+1]-nums[i];
            if ((preDiff<=0&&curDiff>0) || (preDiff>=0&&curDiff<0)) {
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};

// 法2 动态规划
class Solution3 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<=1) {
            return nums.size();
        }
        int dp[1000][2];
        std::fill(&dp[0][0], &dp[0][0]+2000, 1);    // 序列长度至少为1
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i=1; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j]>nums[i]) {
                    dp[i][0] = std::max(dp[i][0], dp[j][1]+1);
                }
            }
            for (int j=0; j<i; ++j) {
                if (nums[j]<nums[i]) {
                    dp[i][1] = std::max(dp[i][1], dp[j][0]+1);
                }
            }
        }
        return std::max(dp[nums.size()-1][0], dp[nums.size()-1][1]);

    }
};