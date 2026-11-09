
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = graph.size();
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        path.push_back(0);
        
        std::function<void(int)> dfs = [&](int u) {
            if (u == n-1) {
                res.push_back(path);
                return;
            }

            for (int v: graph[u]) {
                path.push_back(v);
                dfs(v);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};

int main() {
    
    return 0;
}