#include "../../utils/utils.h"


class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        const int n = equations.size();
        const int m = queries.size();
        for (int i=0; i<2*n; ++i) {
            p.push_back(i);
            w.push_back(1.0);
        }
        std::unordered_map<std::string, int> mp;

        int idx = 0;
        for (int i=0; i<n; ++i) {
            std::string a = equations[i][0], b = equations[i][1];
            
            if (mp.find(a) == mp.end()) mp[a] = idx++;
            if (mp.find(b) == mp.end()) mp[b] = idx++;

            int p_a = find(mp[a]), p_b = find(mp[b]);
            if (p_a == p_b) continue;
            p[p_a] = p_b;
            w[p_a] = values[i] * w[mp[b]] / w[mp[a]];
        }

        std::vector<double> res;
        for (int i=0; i<m; ++i) {
            std::string c = queries[i][0], d = queries[i][1];
            if (mp.find(c) == mp.end() || mp.find(d) == mp.end()) {
                res.push_back(-1.0);
                continue;
            }

            int p_c = find(mp[c]), p_d = find(mp[d]);
            if (p_c != p_d) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(w[mp[c]] / w[mp[d]]);
            
        }

        return res;
    }

private:
    std::vector<int> p; // 存放并查集的父指针
    std::vector<double> w; // 权重数组，节点与其父节点的比值

    // 获取父节点
    int find(int x) {
        if (p[x] == x) return x;

        int origin = p[x]; // 原始父节点
        p[x] = find(p[x]); // 更新父节点为根节点
        w[x] *= w[origin]; // w[x] = v[x]/v[origin] -> w[x] = v[x]/v[root] = (v[x]/v[origin])*(v[orign]/v[root])
        return p[x];
    }
};