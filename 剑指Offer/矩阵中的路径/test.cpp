#include "../../utils/utils.h"


class Solution {
public:
    bool wordPuzzle(std::vector<std::vector<char>>& grid, std::string target) {
        const int m = grid.size();
        if (m==0) return false;
        const int n = grid[0].size();
        const int l = target.size();
        if (l==0) return true;

        int dir[5] = {-1, 0, 1, 0, -1};

        std::function<bool(int i, int j, int k)> dfs = [&](int i, int j, int k) -> bool {
            if (k==l) return true;
            if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!=target[k]) return false;
            grid[i][j] = '~';
            bool ans = false;
            for (int a=0; a<4; ++a) {
                ans = ans || dfs(i+dir[a], j+dir[a+1], k+1);
            }
            grid[i][j] = target[k];
            return ans;
        };
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }

    bool wordPuzzle1(std::vector<std::vector<char>>& grid, std::string target) {
        const int m = grid.size();
        if (m==0) return false;
        const int n = grid[0].size();
        const int l = target.size();
        if (l==0) return true;

        int dir[5] = {-1, 0, 1, 0, -1};
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
        std::function<bool(int i, int j, int k)> dfs = [&](int i, int j, int k) -> bool {
            if (k==l-1 && grid[i][j]==target[k]) return true;
            if (grid[i][j]!=target[k]) return false;
            visited[i][j] = true;
            for (int a=0; a<4; ++a) {
                int ii = i+dir[a], jj = j+dir[a+1];
                if (ii<0 || ii>=m || jj<0 || jj>=n || visited[ii][jj]) continue;
                if (dfs(ii, jj, k+1)) return true;
            }
            visited[i][j] = false;
            return false;
        };
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};