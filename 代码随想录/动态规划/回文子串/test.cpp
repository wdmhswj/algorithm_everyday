#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int result=0;
        for(int i=s.size()-1; i>=0; --i){
            for(int j=i; j<s.size(); ++j) {
                if(s[i]==s[j]) {
                    if(j-i<=1){
                        ++result;
                        dp[i][j]=1;
                    }else if(dp[i+1][j-1]){ // 据此，遍历顺序从下向上，从左到右
                        ++result;
                        dp[i][j]=1;
                    }
                }
            }
        }
        return result;

    }

    // 优化版
    int countSubstrings1(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        int result=0;
        for(int i=s.size()-1; i>=0; --i){
            int pre=0;  // dp[i+1][j-1]
            for(int j=i; j<s.size(); ++j) {
                int tmp=dp[j];  // dp[i+1][j]
                if(s[i]==s[j]) {
                    if(j-i<=1){
                        ++result;
                        dp[j]=1;
                    }else if(pre){ // 据此，遍历顺序从下向上，从左到右
                        ++result;
                        dp[j]=1;
                    }else{
                        dp[j]=0;
                    }      
                }else{
                    dp[j]=0; 
                }
                pre=tmp;
            }
        }
        return result;

    }
};