#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        const int n = edges.size();
        _p.resize(n+1);
        for (int i=1; i<=n; ++i) {
            _p[i] = i;
        }
        for (const auto& edge: edges) {
            if (_find(edge[0])==_find(edge[1])) {
                return edge;
            }
            _p[_find(edge[0])] = _find(edge[1]);
        }
        return {};
    }

private:
    std::vector<int> _p;
    int _find(int x) {
        if (x != _p[x]) _p[x] = _find(_p[x]);
        return _p[x];
    }
};