#include <vector>

using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=0; i<m; i++){
            if (obstacleGrid[i][0]==1) {
                for(int j=i; j<m; j++){ // 第0列[i, 0]及之后的元素都无法到达
                    dp[j][0]=0;
                }
                break;
            }
        }
        for(int j=0; j<n; j++){
            if (obstacleGrid[0][j]==1) {
                for(int i=j; i<n; i++){
                    dp[0][i]=0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if (obstacleGrid[i][j]==1) {
                    dp[i][j]=0;
                } else {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};