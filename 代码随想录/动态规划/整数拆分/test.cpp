#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i/2; ++j){  // 因为有j*(i-j)，所以j只需到i/2
                dp[i]  = std::max(dp[i], std::max( j*(i-j), j*dp[i-j]));

            }
        }
        return dp[n];
    }
};