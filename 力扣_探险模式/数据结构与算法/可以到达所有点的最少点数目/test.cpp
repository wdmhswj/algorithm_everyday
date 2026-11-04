
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<int> inDegree(n, 0);
        for (auto& e: edges) {
            ++inDegree[e[1]];
        }
        std::vector<int> res;
        res.reserve(n);
        for (int i=0; i<n; ++i) {
            if (inDegree[i]==0) res.push_back(i);
        }
        return res;
    }
};

int main() {
    
    return 0;
}