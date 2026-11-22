
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size();
        if (m==0) return {};
        const int n = isWater[0].size();
        if (n==0) return {};

        std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));

        std::queue<std::pair<int, int>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isWater[i][j]==1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i=0; i<4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i+1];
                if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
                if (res[nx][ny] != -1) continue;
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return res;
    }
};

int main() {
    
    return 0;
}