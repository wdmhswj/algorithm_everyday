#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s.size()==1) {
            return 1;
        }
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i=n-1; i>=0; --i){
            for(int j=i; j<n; ++j){
                if (s[i]==s[j]) {
                    if (j-i==1) {
                        dp[i][j]=2;
                    }else if (j-i>=2) {
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }else {
                    if (j-i>=2) {
                        dp[i][j]=std::max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }

    // 优化版
    int longestPalindromeSubseq1(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s.size()==1) {
            return 1;
        }
        int n=s.size();
        vector<int> dp(n, 1);   // dp[n-1][j]=1, j=0,1,...,n-1
        for(int i=n-1; i>=0; --i){
            int pre=1;
            for(int j=i; j<n; ++j){
                int tmp=dp[j];  // dp[i+1][j]
                if (s[i]==s[j]) {
                    if (j-i==1) {
                        dp[j]=2;
                    }else if (j-i>=2) {
                        dp[j]=pre+2;
                    }else{
                        dp[j]=1;
                    }
                }else {
                    if (j-i>=2) {
                        dp[j]=std::max(dp[j], dp[j-1]);
                    }else{
                        dp[j]=1;
                    }
                }
                pre=tmp;
            }
        }
        return dp[n-1];
    }
};