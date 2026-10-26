
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> comb;
        _backtrack(res, n, k, comb, 1);

        return res;
    }

private:
    void _backtrack(std::vector<std::vector<int>>& res, int n, int k, std::vector<int>& comb, int cur) {
        if (comb.size()>=k) {
            res.push_back(comb);
            return;
        }
        for (int i=cur; i<=n; ++i) {
            comb.push_back(i);
            _backtrack(res, n, k, comb, i+1);
            comb.pop_back();
        }
    }
};

int main() {
    
    return 0;
}