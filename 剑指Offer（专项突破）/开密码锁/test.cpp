#include "../../utils/utils.h"

class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> dde(deadends.begin(), deadends.end());
        if (dde.count("0000") || dde.count(target)) return -1;
        if (target == "0000") return 0;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        q.emplace("0000");
        int res = 0;
        while (!q.empty()) {
            ++res;
            for (int i=q.size(); i>0; --i) {
                std::string cur = q.front(); q.pop();
                for (auto around: _get(cur)) {
                    if (visited.count(around) || dde.count(around))
                        continue;
                    if (around == target)
                        return res;
                    q.emplace(around);
                    visited.insert(around);
                }
            }
        }
        return -1;
    }

private:
    char prev(char cur) {
        return cur=='0' ? '9' : cur-1;
    }
    char next(char cur) {
        return cur=='9' ? '0' : cur+1;
    }

    std::vector<std::string> _get(std::string& s) {
        std::vector<std::string> res;
        for (int i=0; i<4; ++i) {
            char cur = s[i];
            s[i] = prev(cur);
            res.emplace_back(s);
            s[i] = next(cur);
            res.emplace_back(s);
            s[i] = cur;
        }
        return res;
    }
};