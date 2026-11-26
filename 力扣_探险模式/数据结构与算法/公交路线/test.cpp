

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        std::unordered_map<int, std::vector<int>> station2Routes;
        const int n = routes.size();
        for (int i=0; i<n; ++i) {
            for (int station: routes[i]) {
                station2Routes[station].push_back(i);
            }
        }

        if (!station2Routes.count(source)) return -1;

        std::vector<int> visitedRoute(n, false);
        std::queue<int> q;
        for (int r: station2Routes[source]) {
            visitedRoute[r] = true;
            q.push(r);
        }

        int buses = 0;
        while (!q.empty()) {
            ++buses;
            for (int i=q.size(); i>0; --i) {
                int r = q.front(); q.pop();
                for (int station: routes[r]) {
                    if (station == target) return buses;

                    for (int nr: station2Routes[station]) {
                        if (!visitedRoute[nr]) {
                            visitedRoute[nr] = true;
                            q.push(nr);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    
    return 0;
}