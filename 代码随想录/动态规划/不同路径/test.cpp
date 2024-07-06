#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 || n==1) {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths1(int m, int n) {
        if (m==1 || n==1) {
            return 1;
        }
        vector<int> dp(n, 1);   // 只需使用一维数组保存上一行的结果
        for(int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                dp[j]=dp[j]+dp[j-1];    // 
            }
        }
        return dp[n-1];
    }
};