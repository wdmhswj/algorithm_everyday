#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        dp[0]=0;
        for(int i=1; i*i<=n; ++i) {
            int square = i * i;
            for (int j = square; j <= n; ++j) {
                dp[j] = std::min(dp[j], dp[j - square] + 1);
            }
        }
        return dp[n];
    }
};