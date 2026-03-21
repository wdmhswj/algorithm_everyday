#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(1, n, cur, k, res);
        return res;
    }
private:
    void backtrack(int i, int n, std::vector<int>& cur, int k, std::vector<std::vector<int>>& res) {
        if (cur.size()==k) {
            res.push_back(cur);
            return;
        }

        for (int j=i; j<=n; ++j) {
            cur.push_back(j);
            backtrack(j+1, n, cur, k, res);
            cur.pop_back();
        }
    }
};