#include <string>
#include <vector>


using std::string;
using std::vector;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.empty()) {
            return true;
        }
        if (s.empty()) {
            return false;
        }
        if (s.size()<t.size()) {
            return false;
        }
        
        vector<vector<unsigned long long>> dp(s.size()+1, vector<unsigned long long>(t.size()+1, 0));

        for(int i=0; i<=s.size(); ++i) {
            dp[i][0]=1;
        }
        for(int i=1; i<=s.size(); ++i) {
            for(int j=1; j<=t.size(); ++j) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                } else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }

    // 优化版
    int numDistinct1(string s, string t) {
       if (s.size()<t.size()) {
            return 0;
        }
        
        vector<unsigned long long> dp(t.size()+1, 0);


        dp[0]=1;

        for(int i=1; i<=s.size(); ++i) {
            int pre=0;
            for(int j=1; j<=t.size(); ++j) {
                int tmp=dp[j];
                if (s[i-1]==t[j-1]) {
                    dp[j]=pre+dp[j];
                }
                pre =tmp;
            }
        }
        return dp[t.size()];
    }
};