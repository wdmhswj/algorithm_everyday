#include "../../utils/utils.h"

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        const int n = isConnected.size();
        _p.resize(n);
        for (int i=0; i<n; ++i)
            _p[i] = i;

        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                if (isConnected[i][j] == 1) {
                    _p[_find(i)] = _find(j); // i的根节点改为j的根节点 -> 合并
                }
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (i == _p[i]) ++res; // i为根节点
        }
        return res;
    }

private:
    std::vector<int> _p;
    int _find(int x) {
        if (x != _p[x]) {
            _p[x] = _find(_p[x]);
        }
        return _p[x];
    }
};


class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        const int n = isConnected.size();
        std::vector<bool> isVisited(n, false);

        std::function<void(int)> dfs = [&](int cur) {
            isVisited[cur] = true;
            for (int i=0; i<n; ++i) {
                if (!isVisited[i] && isConnected[cur][i] == 1)
                    dfs(i);
            }
        };

        int res = 0;
        for (int i=0; i<n; ++i) {
            if (!isVisited[i]) {
                ++res;
                dfs(i);
            }
        }

        return res;
    }
};