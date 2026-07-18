#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));
        std::queue<std::pair<int, int>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j]==0) {
                    res[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int i=0; i<4; ++i) {
                int x = cur.first + dirs[i];
                int y = cur.second + dirs[i+1];
                if (x>=0 && x<m && y>=0 && y<n && res[x][y]==-1) {
                    res[x][y] = res[cur.first][cur.second] + 1;
                    // q.push({x, y});
                    q.emplace(x, y);
                }
            }

        }
        return res;
    }
};