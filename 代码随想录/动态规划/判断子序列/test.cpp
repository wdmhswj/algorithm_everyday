#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            return false;
        }
        int i=0, j=0;
        while(i<s.size()) {
            if (j==t.size()) {
                return false;
            }
            if (s[i]==t[j]) {
                ++i;
            }
            ++j;
        }
        return true;
        
    }

    bool isSubsequence1(string s, string t) {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            return false;
        }
        
        int i = 0;  // 指向s的指针
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                ++i;
                if (i == s.size()) {  // 提前结束的优化
                    return true;
                }
            }
        }
        return false;
    }

    bool isSubsequence2(string s, string t) {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            return false;
        }
        if (s.size()>t.size()) {
            return false;
        }
        
        vector<int> dp(s.size()+1, 0);
        for(int i=1; i<=t.size(); ++i){
            int pre=0;  // dp[i-1][j-1]
            for(int j=1; j<=s.size(); ++j) {
                int tmp=dp[j];  // 前一个外循环的dp[i-1][j]
                if (t[i-1]==s[j-1]) {
                    dp[j]=pre+1;
                } else {
                    dp[j]=std::max(dp[j], dp[j-1]);
                }
                pre = tmp;
            }
        }
        return dp[s.size()]==s.size();
    }
};