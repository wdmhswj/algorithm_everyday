#include "../../utils/utils.h"

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int res = 0;
        const int m = grid.size();
        const int n = grid[0].size();

        int dirs[5] = {-1, 0, 1, 0, -1};
        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (grid[i][j] == 0) return 0;
            int ans = 1;    // 当前节点为岛屿的一部分
            grid[i][j]=0;   // 置零表示已访问，防止之后再次访问同一岛屿的节点
            for (int k=0; k<4; ++k) {
                int x=i+dirs[k], y=j+dirs[k+1];
                if (x>=0 && x<m && y>=0 && y<n)
                    ans += dfs(x, y);
            }
            return ans;
        };

        for (int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                res = std::max(res, dfs(i, j));
            }
        }

        return res;
    }
};