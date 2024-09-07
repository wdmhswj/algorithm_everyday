#include <algorithm>
#include <unordered_map>
#include <vector>
#include "../../utils/printH.h"
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        // dp初始化
        for(int i=0; i<=k; ++i)
        {
            dp[0][i] = 1;
        }
        int res = 1;

        // printVector2D(dp);

        for(int i=1; i<=n-1; ++i)
        {
            for(int m=0; m<i; ++m)
            {
                if(nums[m]==nums[i])
                {
                    dp[i][0] = std::max(dp[i][0], dp[m][0]+1);
                }else{
                    dp[i][0] = std::max(1, dp[i][0]);
                }
            }
            // printVector2D(dp);
            res = std::max(res, dp[i][0]);
        }

        // printVector2D(dp);

        for(int i=1; i<=n-1; ++i)        
        {
            for(int j=1; j<=k; ++j)
            {
                for(int m=0; m<i; ++m)
                {
                    if(nums[m]==nums[i])
                    {
                        dp[i][j] = std::max(dp[m][j]+1, dp[i][j]);
                    }else{
                        dp[i][j] = std::max(dp[m][j-1]+1, dp[i][j]);
                    }
                }
                res = std::max(dp[i][j], res);
            }

            
        }

        // printVector2D(dp);
        return res;
    }
    int maximumLength2(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        int res = 1;


        for(int i=0; i<=n-1; ++i)        
        {
            dp[i][0] = 1;
            for(int j=0; j<=k; ++j)
            {
                for(int m=0; m<i; ++m)
                {
                    int flag = nums[m]!=nums[i];
                    if(j-flag>=0 ){
                        dp[i][j] = std::max(dp[i][j], dp[m][j-flag]+1);
                    }
                }
                res = std::max(dp[i][j], res);
            }

            
        }

        return res;
    }

    // 优化版
    int maximumLength3(vector<int>& nums, int k) {
        const int n = nums.size();
        std::unordered_map<int, vector<int>> dp;
        vector<int> zd(k+1, 0);


        for(int i=0; i<=n-1; ++i)        
        {
            int v = nums[i];    // 以nums[i]结尾的序列
            if(!dp.count(v))    // 之前还没遇到
            {
                dp[v] = vector<int>(k+1, 0);
            }

            auto& tmp = dp[v];  // 以v结尾的k+1种序列长度
            for(int j=0; j<=k; ++j)
            {
                ++tmp[j];   // 因为当前元素nums[i]==v，则可以直接加入v结尾的序列的结尾
                if(j>0)
                {
                    // 若nums[x]!=nums[i]，则zd[j-1]+1代表最多j个不等的
                    // 若nums[x]==nums[i]，则zd[j-1]+1代表最多j-1个不等的，也符合要求
                    tmp[j] = std::max(tmp[j], zd[j-1]+1);
                }
            }
            for(int j=0; j<=k; ++j)
            {
                zd[j] = std::max(zd[j], tmp[j]);
            }
        }
        return zd[k];   // 实际上zd[k]代表不超过k个不等的最长子序列的长度
    }
};

int main(){
    Solution s;
    vector<int> nums = {
        1,2,3,4,5,1
    };
   std::cout<<s.maximumLength2(nums, 0);
}