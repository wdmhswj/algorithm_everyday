#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;

        const int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, true));
        for (int i=n-1; i>=0; --i) {
            for (int j=i+1; j<n; ++j) {
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
            }
        }
        std::vector<std::string> path;
        
        std::function<void(int)> backtrack = [&](int start) {
            if (start==n) {
                res.emplace_back(path);
                return;
            }

            for (int end=start; end<n; ++end) {
                if (dp[start][end]) {
                    path.emplace_back(s.substr(start, end-start+1));
                    backtrack(end+1);
                    path.pop_back();
                }
            }
        };
        backtrack(0);
        return res;
    }


};