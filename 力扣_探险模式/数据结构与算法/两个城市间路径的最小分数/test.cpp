
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> neighbors;
        for (auto& road: roads) {
            neighbors[road[0]].push_back({road[1], road[2]});
            neighbors[road[1]].push_back({road[0], road[2]});
        }
        std::vector<bool> visited(n+1, false);

        int res = INT_MAX;
        std::function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto& [v, w] : neighbors[u]) {
                res = std::min(res, w);
                if (!visited[v]) dfs(v);
            }
        };

        dfs(1);
        return res; 
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& r : roads) {
            int u = r[0], v = r[1], w = r[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;

        // BFS 遍历节点 1 所在连通分量
        queue<int> q;
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, w] : g[u]) {
                ans = min(ans, w);          // 更新最小边权
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}