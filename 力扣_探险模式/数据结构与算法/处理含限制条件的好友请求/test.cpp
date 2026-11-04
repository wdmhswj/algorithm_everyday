
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {

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

        auto canMerge = [&](int ra, int rb) -> bool {
            for (auto& r: restrictions) {
                int rx = find(r[0]), ry = find(r[1]);
                if (ra == rx && rb == ry || ra == ry && rb == rx) return false;
            }
            return true;
        };
        
        std::vector<bool> res;
        res.reserve(requests.size());
        for (std::vector<int>& v: requests) {
            int ra = find(v[0]), rb = find(v[1]);
            if (ra == rb) {
                res.push_back(true);
            } else if (canMerge(ra, rb)) {
                unite(ra, rb);
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        // 并查集
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // 迭代式 find + 路径压缩
        function<int(int)> find = [&](int x) {
            int root = x;
            while (parent[root] != root) root = parent[root];
            while (parent[x] != x) {
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        };

        // 每个根维护的禁止集合
        vector<unordered_set<int>> cant(n);
        for (auto& r : restrictions) {
            int a = r[0], b = r[1];
            cant[a].insert(b);
            cant[b].insert(a);
        }

        vector<bool> ans;
        ans.reserve(requests.size());

        for (auto& req : requests) {
            int u = req[0], v = req[1];
            int ru = find(u), rv = find(v);

            // 已经是朋友：请求一定成功
            if (ru == rv) {
                ans.push_back(true);
                continue;
            }

            // 合并会违反限制：请求失败
            if (cant[ru].count(rv)) {
                ans.push_back(false);
                continue;
            }

            // 合并合法：请求成功
            ans.push_back(true);

            // 启发式合并：把小的禁止集合并入大的
            if (cant[ru].size() > cant[rv].size()) {
                swap(ru, rv);
            }

            // 把 cant[ru] 里的禁止关系传播到 rv
            for (int x : cant[ru]) {
                int rx = find(x);      // 历史根转当前根
                cant[rv].insert(rx);
                cant[rx].insert(rv);   // 双向
            }

            parent[ru] = rv;           // ru 并入 rv
        }

        return ans;
    }
};

};

int main() {
    
    return 0;
}