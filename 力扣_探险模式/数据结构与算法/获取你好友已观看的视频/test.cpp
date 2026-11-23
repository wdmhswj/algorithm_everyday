
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        const int n = watchedVideos.size();
        std::vector<int> dist(n, -1);
        std::queue<int> q;
        dist[id] = 0;
        q.push(id);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (dist[cur] == level) continue;

            for (int next: friends[cur]) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur]+1;
                    q.push(next);
                }
            }
        }

        std::unordered_map<std::string, int> frq;
        for (int i=0; i<n; ++i) {
            if (dist[i] == level) {
                for (const std::string& v: watchedVideos[i]) {
                    ++frq[v];
                }
            }
        }

        std::vector<std::pair<std::string, int>> items(frq.begin(), frq.end());

        std::sort(items.begin(), items.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        std::vector<std::string> res;
        res.reserve(items.size());
        for (auto& [v, cnt]: items) {
            res.push_back(v);
        }

        return res;
    }
};
int main() {
    
    return 0;
}