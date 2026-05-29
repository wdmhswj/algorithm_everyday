#include "../../utils/utils.h"

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        const int n = triangle.size();
        if (n == 0) return 0;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=i; ++j) {
                dp[i][j] = triangle[i-1][j-1] + std::min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        int result = INT_MAX;
        for (int j=1; j<=n; ++j) {
            result = std::min(result, dp[n][j]);
        }
        return result;
    }


    int minimumTotal_1(std::vector<std::vector<int>>& triangle) {
        const int n = triangle.size();
        if (n == 0) return 0;
        std::vector<int> dp(n, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i=1; i<n; ++i) {
            for (int j=i; j>0; --j) {
                std::cout << "i: " << i << ", j: " << j << ", dp[j]: " << dp[j] << ", dp[j-1]: " << dp[j-1] << ", triangle[i][j]: " << triangle[i][j] << std::endl;
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j-1]);
                std::cout << "更新后 dp[j]: " << dp[j] << std::endl;
            }
            dp[0] += triangle[i][0];
            std::cout << "更新后 dp[0]: " << dp[0] << std::endl;
        }
        int result = INT_MAX;
        for (int j=0; j<n; ++j) {
            result = std::min(result, dp[j]);
        }
        return result;
    }
};


int main() {
    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    Solution solution;
    // int result = solution.minimumTotal(triangle);
    // std::cout << "Minimum path sum: " << result << std::endl;

    int result_1 = solution.minimumTotal_1(triangle);
    std::cout << "Minimum path sum (optimized): " << result_1 << std::endl;

    return 0;
}