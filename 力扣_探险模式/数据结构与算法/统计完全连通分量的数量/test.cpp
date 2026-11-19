

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        std::vector<std::unordered_set<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        std::vector<bool> visited(n, false);

        
        std::function<void(int, std::vector<int>&)> dfs = [&](int cur, std::vector<int>& path) {
            visited[cur] = true;
            path.push_back(cur);

            for (int neighbor: adj[cur]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, path);
                }
            }

            return true;
        };

        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                std::vector<int> path;
                dfs(i, path);
                bool isComplete = true;
                for (int u: path) {
                    if (adj[u].size() != path.size()-1) {
                        isComplete = false;
                        break;
                    }
                }
                res += isComplete;
            }
        }

        return res;
    }
};

int main() {
    
    return 0;
}