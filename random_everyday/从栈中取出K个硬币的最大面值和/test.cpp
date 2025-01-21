#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        const int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1));

        // dp[i][j] = max( dp[i][j], dp[i-1][j-p-1] + w[i][p])
        // dp[0][j] = dp[i][0] = 0
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=k; ++j) {
                dp[i][j] = dp[i-1][j];                                                      // 当前栈不选任何硬币
                int w = 0;
                for(int p=0; p<std::min(static_cast<int>(piles[i-1].size()), j); ++p) {
                    w += piles[i-1][p];                                                     // 前p+1个硬币之和
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-p-1]+w);
                }
                
            }
        }
        return dp[n][k];
    }
    int maxValueOfCoins_1(vector<vector<int>>& piles, int k) {
        const int n = piles.size();
        vector<int> dp(k+1);

        int sum_n = 0;
        for(int i=1; i<=n; ++i) {
            sum_n = std::min(sum_n+static_cast<int>(piles[i-1].size()), k);
            for(int j=sum_n; j>=0; --j) {
                // dp[i][j] = dp[i-1][j];                                                      // 当前栈不选任何硬币
                int w = 0;
                for(int p=0; p<std::min(static_cast<int>(piles[i-1].size()), j); ++p) {
                    w += piles[i-1][p];                                                     // 前p+1个硬币之和
                    dp[j] = std::max(dp[j], dp[j-p-1]+w);
                }
                
            }
        }
        
        return dp[k];
    }
};


