
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<std::vector<int>> neighbors(n);
        for (auto& e: edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        std::vector<bool> visited(n, false);

        std::function<bool(int)> dfs = [&](int cur) -> bool {
            if (cur == destination) return true;
            visited[cur] = true;

            for (int node: neighbors[cur]) {
                if (!visited[node] && dfs(node)) return true;
            }
            return false;
        };

        return dfs(source);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == destination) return true;
            for (int v : g[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}