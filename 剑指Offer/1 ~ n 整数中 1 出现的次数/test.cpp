#include "../../utils/utils.h"

class Solution {
public:
    int digitOneInNumber(int n) {
        std::string s = std::to_string(n);
        int m = s.length();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, -1));

        std::function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
            if (i==m) return cnt1;
            if (!is_limit && dp[i][cnt1]>=0) return dp[i][cnt1];
            int up = is_limit ? s[i]-'0' : 9;
            int res = 0;
            for (int j=0; j<=up; ++j) {
                res += f(i+1, cnt1+(j==1), is_limit&&j==up);
            }
            if (!is_limit) dp[i][cnt1] = res;
            return res;
        };
        return f(0, 0, true);

    }
};

int main() {    
    Solution s;
    std::cout << s.digitOneInNumber(110) << std::endl;
    return 0;
}