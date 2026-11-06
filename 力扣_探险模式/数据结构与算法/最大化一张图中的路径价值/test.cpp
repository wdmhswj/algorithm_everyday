
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        const int n = values.size();
        std::vector<bool> visited(n, false);
        std::vector<std::vector<std::pair<int, int>>> neighborNodes(n);

        for (auto& e: edges) {
            neighborNodes[e[0]].push_back({e[1], e[2]});
            neighborNodes[e[1]].push_back({e[0], e[2]});
        }

        int curVal = values[0];
        int usedTime = 0;
        visited[0] = true;
        int res = 0;
        std::function<void(int, int, int)> dfs = [&](int curNode, int curVal, int usedTime) {
            if (curNode == 0) {
                res = std::max(res, curVal);
            }

            // 判断邻居节点是否可以加入路径
            for (auto& p: neighborNodes[curNode]) {
                if (usedTime + p.second <= maxTime) {
                    if (!visited[p.first]) {
                        visited[p.first] = true;
                        dfs(p.first, curVal + values[p.first], usedTime + p.second);
                        visited[p.first] = false;
                    } else {
                        dfs(p.first, curVal, usedTime + p.second);
                    }
                }
            }

        };

        dfs(0, curVal, usedTime);
        return res;
    }
};

int main() {
    
    return 0;
}