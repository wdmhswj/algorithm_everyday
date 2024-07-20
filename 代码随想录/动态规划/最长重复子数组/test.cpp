#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return 0;
        }
        
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        // dp[0][0]=nums1[0]==nums2[0]?1:0;
        int res=0;
        for(int i=1; i<=nums1.size(); ++i) {
            for(int j=1; j<=nums2.size(); ++j) {
                if (nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                res=std::max(res, dp[i][j]);
            }
        }
        return res;
    }

    // 优化版：使用滚动数组
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return 0;
        }
        
        vector<int> dp(nums2.size()+1, 0);
        // dp[0][0]=nums1[0]==nums2[0]?1:0;
        int res=0;
        for(int i=1; i<=nums1.size(); ++i) {
            for(int j=nums2.size(); j>=1; --j) {
                if (nums1[i-1]==nums2[j-1]) {
                    dp[j]=dp[j-1]+1;
                } else {
                    dp[j]=0;    // 由于上一层的dp[i-1][j]可能不为0
                }
                res=std::max(res, dp[j]);
            }
        }
        return res;
    }
};