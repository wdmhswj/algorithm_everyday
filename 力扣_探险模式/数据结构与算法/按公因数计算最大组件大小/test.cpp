
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        const int n = nums.size();
        int maxVal = *std::max_element(nums.begin(), nums.end());

        // 1. 预处理最小质因数 SPF
        std::vector<int> spf(maxVal+1);
        for (int i=0; i<=maxVal; ++i) spf[i]=i;
        for (int i=2; (long long)i*i<=maxVal; ++i) {
            if (spf[i]==i) {
                for (long long j = (long long)i*i; j<=maxVal; j+=i) {
                    if (spf[j]==j) spf[j] = i;
                }
            }
        }
        // 2. 并查集：0..n-1 数组元素，n+p 是 质因数 p
        int total = n + maxVal + 1;
        std::vector<int> parent(total), sz(total, 0);
        for (int i=0; i<total; ++i) parent[i] = i;
        for (int i=0; i<n; ++i) sz[i] = 1;

        auto find = [&](int x) {
            int root = x;
            while (root != parent[root]) root = parent[root];

            while (x != parent[x]) {
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        };

        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (sz[ra] < sz[rb]) std::swap(ra, rb);
            parent[rb] = ra;
            sz[ra] += sz[rb];
        };

        // 3. 对于每个数组元素分解质因数，并与质因数合并
        for (int i=0; i<n; ++i) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                unite(i, n+p);
                while (x%p == 0) x /= p;
            }
        }

        // 4. 取最大集合元素
        int res = 0;
        for (int i=0; i<n; ++i) {
            res = std::max(res, sz[find(i)]);
        }
        return res;
    }
};

int main() {
    
    return 0;
}