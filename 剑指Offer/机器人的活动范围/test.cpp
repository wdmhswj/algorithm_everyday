#include "../../utils/utils.h"
class Solution {
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        auto Val = [](int x) {
            return x%10 + x/10;
        };
        int dir[5] = {-1, 0, 1, 0, -1};
        std::function<int(int i, int j)> dfs = [&](int i, int j) -> int {
            if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || Val(i)+Val(j)>cnt) return 0;
            int ans = 1;
            visited[i][j]=true;
            for (int a=0; a<4; ++a)
            {
                ans += dfs(i+dir[a], j+dir[a+1]);
            }
            // visited[i][j]=false;
            return ans;
        };
        return dfs(0, 0);
    }

    int wardrobeFinishing1(int m, int n, int cnt) {
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        auto Val = [](int x) {
            return x%10 + x/10;
        };
        std::function<int(int i, int j)> dfs = [&](int i, int j) -> int {
            if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || Val(i)+Val(j)>cnt) return 0;
            int ans = 1;
            visited[i][j]=true;
            return 1 + dfs(i+1, j) + dfs(i, j+1);
        };
        return dfs(0, 0);
    }
};