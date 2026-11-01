
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;

        std::unordered_map<int, int> idx;
        for (int i=0; i<n; ++i) idx[nums[i]] = i;

        std::vector<int> parent(n), sz(n, 1);
        for (int i=0; i<n; ++i) parent[i] = i;

        std::function<int(int)> find = [&](int x) -> int {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (sz[ra] < sz[rb]) std::swap(ra, rb);
            parent[rb] = ra;
            sz[ra] += sz[rb];
        };

        for (auto& [v, i]: idx) {
            auto it = idx.find(v + 1);
            if (it != idx.end()) {
                unite(i, it->second);
            }
        }

        return *std::max_element(sz.begin(), sz.end());
    }
};

int main() {
    
    return 0;
}