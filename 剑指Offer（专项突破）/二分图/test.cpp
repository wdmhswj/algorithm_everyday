#include "../../utils/utils.h"

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        const int n = graph.size();
        if (n <= 1) return false;

        std::unordered_set<int> A, B;
        for (int u=0; u<n; ++u) {
            if (A.empty() && B.empty()) {
                A.insert(u);
                for (const int& v: graph[u]) {
                    B.insert(v);
                }
                continue;
            } 

            

            for (const int& v: graph[u]) {
                // if (A.empty() && B.empty()) {
                //     A.insert(u);
                //     B.insert(v);
                //     continue;
                // }

                // auto it_1 = A.find(u);
                // if (it_1 != A.end()) {
                //     auto it_2 = B.find(v);
                //     if (it_2 == B.end()) return false;
                // } else {
                //     auto it_3 = B.find(u);
                //     if (it_3 != B.end()) {
                //         auto it_4 = A.find(v);
                //         if (it_4 == A.end()) return false;
                //     } else {
                //         return false;
                //     }
                // }

                bool uInA = isIn(u, A);
                bool uInB = isIn(u, B);
                bool vInA = isIn(v, A);
                bool vInB = isIn(v, B);
                
                if (uInA) {
                    if (vInB) continue;
                    else if (vInA) return false;
                    else B.insert(v);
                } else if (uInB) {
                    if (vInA) continue;
                    else if (vInB) return false;
                    else A.insert(v);
                } else {
                    if (vInA) B.insert(u);
                    else if (vInB) A.insert(u);
                    else return false;
                }


            }
        }
        return true;
    }

private:
    bool isIn(const int node, const std::unordered_set<int>& A) {
        auto it = A.find(node);
        return it != A.end();
    }
};


class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        const int n = graph.size();
        if (n <= 0) return false;
        _p.resize(n);
        for (int i=0; i<n; ++i) _p[i] = i;
        for (int u=0; u<n; ++u) {
            for (int v: graph[u]) {
                if (_find(u) == _find(v)) return false;
                _p[_find(v)] = _find(graph[u][0]);  // 将v所在集合的代表节点的父节点设置为u的第一个邻居所在集合的代表节点，即将v所在集合合并到u的第一个邻居所在集合
            }
        }
        return true;
    }

private:
    std::vector<int> _p;    // 每个节点的父节点
    int _find(int x) {
        if (x != _p[x]) _p[x] = _find(_p[x]);
        return _p[x];
    }
};