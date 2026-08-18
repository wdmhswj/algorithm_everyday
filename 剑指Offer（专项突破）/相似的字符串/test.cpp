#include "../../utils/utils.h"

class Solution {
public:
    int numSimilarGroups(std::vector<std::string>& strs) {
        const int n = strs.size();
        if (n==0) return 0;
        const int len = strs[0].size();
        
        _p.resize(n);
        for (int i=0; i<n; ++i) {
            _p[i] = i;
        }

        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) { // i和 j 之间的字符串只需要比较一次
                if (_isSimilar(strs[i], strs[j])) {
                    _p[_find(j)] = _find(i); // 合并两个相似的字符串
                }
            }
        }

        int res = 0;
        for (int i=0; i<n; ++i) {
            if (i==_find(i)) ++res; // 根节点的父节点为它自身
        }
        return res;
    }


private:
    // 检查是否相似
    bool _isSimilar(const std::string& a, const std::string& b) {
        int cnt = 0;
        for (int i=0; i<a.size(); ++i) {
            if (a[i]!=b[i]) ++cnt;
        }
        return cnt<=2;
    }

    // 并查集实现
    std::vector<int> _p; // 父节点
    int _find(int x) {
        if (_p[x] != x) {
            _p[x] = _find(_p[x]);
        }
        return _p[x];
    }
};


int main() {
    std::vector<std::string> strs = {"omv","ovm"};
    Solution s;
    std::cout << s.numSimilarGroups(strs) << std::endl;
    return 0;
}