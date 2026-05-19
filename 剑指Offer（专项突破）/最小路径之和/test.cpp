#include "../../utils/utils.h"

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, grid[0][0]));
        for (int i=1; i<m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j=1; j<n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }

    
    int minPathSum_1(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;


        std::vector<int> dp(n, grid[0][0]);
        for (int j=1; j<n; ++j) {
            dp[j] = dp[j-1] + grid[0][j];
        }

        for (int i=1; i<m; ++i) {
            dp[0] += grid[i][0];
            for (int j=1; j<n; ++j) {
                std::cout << "i: " << i << ", j: " << j << ", dp[j-1]: " << dp[j-1] << ", dp[j]: " << dp[j] << ", grid[i][j]: " << grid[i][j] << std::endl;
                dp[j] = std::min(dp[j], dp[j-1]) + grid[i][j];
                std::cout << "更新后 dp[j]: " << dp[j] << std::endl;
            }
        }

        return dp[n-1];
    }
};


int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    Solution solution;
    int result = solution.minPathSum_1(grid);
    std::cout << "最小路径之和: " << result << std::endl;

    return 0;
}