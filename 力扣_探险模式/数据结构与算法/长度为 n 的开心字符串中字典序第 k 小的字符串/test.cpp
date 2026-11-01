
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        std::vector<std::string> strs;
        std::string path;
        _backtrack(strs, n, path);
        if (strs.size() < k) return "";
        std::sort(strs.begin(), strs.end());
        return strs[k-1];
    }

    string getHappyString(int n, int k) {
        std::string path;
        int cnt = 0;
        return _dfs(n, k, path, cnt);
    }

private:
    void _backtrack(std::vector<std::string>& strs, int n, std::string& path) {
        if (path.size() >= n) {
            strs.push_back(path);
            return;
        }

        for (char c: {'a', 'b', 'c'}) {
            if (path.empty() || c != path.back()) {
                path.push_back(c);
                _backtrack(strs, n, path);
                path.pop_back();
            }
        }

    }

    std::string _dfs(int n, int k, std::string& path, int& cnt) {
        if (path.size() >= n) {
            if (++cnt == k) return path;
            return "";
        }

        for (char c: {'a', 'b', 'c'}) {
            if (path.empty() || c != path.back()) {
                path.push_back(c);
                std::string res = _dfs(n, k, path, cnt);
                if (!res.empty()) return res;
                path.pop_back();
            }
        }
        return "";
    }
};

int main() {
    
    return 0;
}