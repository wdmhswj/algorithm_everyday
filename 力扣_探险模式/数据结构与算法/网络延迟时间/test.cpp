#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 邻接表
        std::vector<std::vector<std::pair<int, int>>> graph(n+1);
        for (auto& t: times) {
            graph[t[0]].push_back({t[1], t[2]});
        }
        
        const int INF = 1e9;
        std::vector<int> dist(n+1, INF);
        dist[k] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq; // 最小堆，{距离，节点}
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            
            if (d > dist[u]) continue; // 过期状态

            for (auto& [v, w]: graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i=1; i<=n; ++i) {
            if (dist[i] == INF) return -1;
            maxTime = std::max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

int main() {
    
    return 0;
}