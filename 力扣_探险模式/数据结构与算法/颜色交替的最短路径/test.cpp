
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // 邻接表：0 红，1 蓝
        vector<vector<int>> red(n), blue(n);
        for (auto& e : redEdges) red[e[0]].push_back(e[1]);
        for (auto& e : blueEdges) blue[e[0]].push_back(e[1]);

        // dist[u][c]：到达 u 且最后一条边颜色为 c 的最短距离
        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q;

        // 起点：两种颜色状态距离都为 0
        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [u, c] = q.front(); q.pop();
            int nd = dist[u][c] + 1;

            if (c == 0) {  // 最后是红色，下一步走蓝色
                for (int v : blue[u]) {
                    if (dist[v][1] == -1) {
                        dist[v][1] = nd;
                        q.push({v, 1});
                    }
                }
            } else {       // 最后是蓝色，下一步走红色
                for (int v : red[u]) {
                    if (dist[v][0] == -1) {
                        dist[v][0] = nd;
                        q.push({v, 0});
                    }
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] != -1 && dist[i][1] != -1)
                ans[i] = min(dist[i][0], dist[i][1]);
            else if (dist[i][0] != -1)
                ans[i] = dist[i][0];
            else if (dist[i][1] != -1)
                ans[i] = dist[i][1];
        }
        return ans;
    }
};


int main() {
    
    return 0;
}