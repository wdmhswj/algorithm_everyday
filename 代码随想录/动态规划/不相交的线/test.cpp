#include <algorithm>
#include <utility>
#include <vector>

using std::vector;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return 0;
        }

        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0 ));

        for(int i=1; i<=nums1.size(); ++i) {
            for(int j=1; j<=nums2.size(); ++j) {
                if (nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }

    // 优化版：使用滚动数组
    int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return 0;
        }

        if (nums1.size()<nums2.size()) {
            std::swap(nums1, nums2);
        }
        vector<int> dp(nums2.size()+1, 0);

        for(int i=1; i<=nums1.size(); ++i) {
            int pre=0;
            for(int j=1; j<=nums2.size(); ++j) {
                int tmp=dp[j];
                if (nums1[i-1]==nums2[j-1]) {
                    dp[j]=pre+1;
                }else{
                    dp[j]=std::max(dp[j], dp[j-1]);
                }
                pre=tmp;
            }
        }
        return dp[nums2.size()];
    }
};