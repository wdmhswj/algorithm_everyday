#include "../../utils/utils.h"

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        std::vector<std::vector<int>> memory(m, std::vector<int>(n, -1)); // 默认为-1以区分是否已计算过以当前节点为起点的最长递增序列长度

        int dirs[5] = {-1, 0, 1, 0, -1};
        // 返回以 (i, j) 为起点的最长递增序列的长度
        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (memory[i][j] != -1) return memory[i][j];
            int len = 1;
            for (int k=0; k<4; ++k) {
                int x = i + dirs[k], y = j + dirs[k+1];
                if (x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j]) {
                    len = std::max(len, 1+dfs(x, y));
                }
            }
            memory[i][j] = len;
            return len;
        };

        int res = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res = std::max(res, dfs(i, j));
            }
        }

        return res;
    }
};