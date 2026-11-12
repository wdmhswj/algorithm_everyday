#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int row = grid.size();
        if (row == 0) return 0;
        const int col = grid[0].size();
        if (col == 0) return 0;

        std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
        int res = 0;

        int dirs[5] = {-1, 0, 1, 0, -1};
        std::function<void(int, int)> dfs = [&](int i, int j) {
            visited[i][j] = true;
            int add = 4;
            for (int k=0; k<4; ++k) {
                int n_i = i + dirs[k];
                int n_j = j + dirs[k+1];
                if (n_i<0 || n_i>=row || n_j<0 || n_j>=col) continue;
                if (grid[n_i][n_j] == 1) {
                    --add;
                    if (!visited[n_i][n_j]) dfs(n_i, n_j);
                }
            }
            res += add;
        };

        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    return res;
                }
            }
        }

        return 0;

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        const int row = grid.size();
        if (row == 0) return 0;
        const int col = grid[0].size();
        if (col == 0) return 0;

        // std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
        int res = 0;

        int dirs[5] = {-1, 0, 1, 0, -1};
        std::function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = 2;
            int add = 4;
            for (int k=0; k<4; ++k) {
                int n_i = i + dirs[k];
                int n_j = j + dirs[k+1];
                if (n_i<0 || n_i>=row || n_j<0 || n_j>=col) continue;
                if (grid[n_i][n_j] != 0) {
                    --add;
                    if (grid[n_i][n_j] == 1) dfs(n_i, n_j);
                }
            }
            res += add;
        };

        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    return res;
                }
            }
        }

        return 0;

    }
};


int main() {
    
    return 0;
}