
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {

        std::unordered_set<long long> edgeSet;
        auto key = [&](int u, int v) -> long long {
            if (u > v) swap(u, v);
            return (long long)u * (n + 1) + v;
        };

        std::vector<int> deg(n, 0);
        for (auto& e: edges) {
            deg[e[0]-1]++;
            deg[e[1]-1]++;
            edgeSet.insert(key(e[0], e[1]));
        }

        auto hasEdge = [&](int u, int v) {
            return edgeSet.count(key(u, v));
        };

        std::vector<int> odd;
        for (int i=0; i<n; ++i) {
            if (deg[i]%2 == 1) {
                odd.push_back(i+1);
            }
        }

        if (odd.size() == 0) {
            return true;
        }
        if (odd.size() == 2) {
            // 是否有边
            // bool hasEdge = false;
            // for (auto& e: edges) {
            //     if (e[0] == odd[0] && e[1] == odd[1] || e[0] == odd[1] && e[1] == odd[0]) {
            //         hasEdge = true;
            //         break;
            //     }
            // }
            if (hasEdge(odd[0], odd[1])) {
                // 找中间节点
                for (int i=1; i<=n; ++i) {
                    if (i != odd[0] && i != odd[1] && !hasEdge(i, odd[0]) && !hasEdge(i, odd[1])) {
                        return true;
                    }   
                }
                // return false;
            } else {
                return true;
            }
        }
        
        if (odd.size() == 4) {
            if (!hasEdge(odd[0], odd[1]) && !hasEdge(odd[2], odd[3])) return true;
            if (!hasEdge(odd[0], odd[2]) && !hasEdge(odd[1], odd[3])) return true;
            if (!hasEdge(odd[0], odd[3]) && !hasEdge(odd[1], odd[2])) return true;
        }

        return false;
    }
};

int main() {
    
    return 0;
}