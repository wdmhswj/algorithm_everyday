#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> countNumbers(int cnt) {
        std::vector<int> ans(std::pow(10, cnt)-1);
        std::iota(ans.begin(), ans.end(), 1);
        return ans;
    }

    std::vector<std::string> countNumbers1(int cnt) {
        std::vector<std::string> ans;
        std::string s;
        std::function<void(int, int)> dfs = [&](int i, int j) {
            if (i==j) {
                ans.push_back(s);
                return;
            }

            int k = i==0 ? 1 : 0;
            for (; k<=9; ++k)
            {
                s.push_back('0'+k);
                dfs(i+1, j);
                s.pop_back();
            }
        };
        for (int i=1; i<=cnt; ++i)
        {
            dfs(0, i);
        }
        return ans;
    }
};