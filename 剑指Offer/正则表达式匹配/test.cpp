#include "../../utils/utils.h"

class Solution {
public:
    bool articleMatch(std::string s, std::string p) {
        
        std::vector<std::vector<int>> f(s.size()+1, std::vector<int>(p.size()+1, 0));

        std::function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (j==p.size()) {
                if (i==s.size()) return true;
                return false;
            }
            if (i==s.size()) {
                if (j+1<p.size() && p[j+1]=='*') return dfs(i, j+2);
                return false;
            }

            if (f[i][j]) return f[i][j]==1;

            int res = -1;

            // std::cout << "s[" << i << "]=" << s[i] << "\tp[" << j << "]="<< p[j] << std::endl;
            // j为*
            // if (p[j]=='*') return dfs(i, j+1);
            // j不为*，j+1为*
            if (j+1<p.size() && p[j+1]=='*') {
                if (dfs(i, j+2) || (s[i]==p[j] || p[j]=='.')&&dfs(i+1, j))
                    res = 1;

            } else if ((s[i]==p[j]||p[j]=='.')&&dfs(i+1, j+1)) {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }

    // 记忆化搜索
    bool articleMatch1(std::string s, std::string p) {
        
        std::vector<std::vector<int>> f(s.size()+1, std::vector<int>(p.size()+1, 0));

        std::function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (j>=p.size()) {
                return i==s.size();
            }

            if (f[i][j]) return f[i][j]==1;

            int res = -1;

            if (j+1<p.size() && p[j+1]=='*') {
                if (dfs(i, j+2) || i<s.size()&&(s[i]==p[j] || p[j]=='.')&&dfs(i+1, j))
                    res = 1;

            } else if (i<s.size()&&(s[i]==p[j]||p[j]=='.')&&dfs(i+1, j+1)) {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }

    // 动态规划
    bool articleMatch2(std::string s, std::string p) {
        const int m = s.size();
        const int n = p.size();
        std::vector<std::vector<bool>> f(m+1, std::vector<bool>(n+1, false));
        f[0][0] = true;
        
        for (int i=0; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                if (p[j-1]=='*') {
                    f[i][j] = f[i][j-2];    // w* 匹配0次
                    if (i && (s[i-1]==p[j-2] || p[j-2]=='.'))
                        f[i][j] = f[i][j] || f[i-1][j];
                } else if (i && (s[i-1]==p[j-1] || p[j-1]=='.')) {
                    f[i][j] = f[i-1][j-1];
                }
            }
        }
        return f[m][n];
        
    }
};


int main() {
    Solution sl;
    std::string s = "aa";
    std::string p = "a*";
    std::cout << sl.articleMatch(s, p) << std::endl;
    s = "ab";
    p = ".*";
    std::cout << sl.articleMatch(s, p) << std::endl;

    s = "a";
    p = "ab*";
    std::cout << sl.articleMatch(s, p) << std::endl;

    s = "bbbba";
    p = ".*a*a";
    std::cout << sl.articleMatch(s, p) << std::endl;

    s = "aaaaaaaaaaaaab";
    p = "a*a*a*a*a*a*a*a*a*a*c";
    std::cout << sl.articleMatch(s, p) << std::endl;
}
