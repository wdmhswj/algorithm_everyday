#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty()||text2.empty()) {
            return 0;
        }
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i=1; i<=text1.size(); ++i) {
            for(int j=1; j<=text2.size(); ++j) {
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=std::max(dp[i][j-1], dp[i-1][j]);
                }
               
            }
        }
        return dp[text1.size()][text2.size()];
    }

    // 优化版：滚动数组
    int longestCommonSubsequence1(string text1, string text2) {
        if (text1.empty()||text2.empty()) {
            return 0;
        }
        if (text1.size()<text2.size()) {
            std::swap(text1, text2);
        }
        vector<int> dp(text2.size()+1, 0);
        for(int i=1; i<=text1.size(); ++i) {
            int prev = 0;   // 相当于dp[i-1][j-1]
            for(int j=1; j<=text2.size(); ++j) {
                int temp=dp[j]; // 保存dp[i-1][j]的值以备下一次迭代使用
                if(text1[i-1]==text2[j-1]) {
                    dp[j]=prev+1;
                }else{
                    dp[j]=std::max(dp[j-1], dp[j]);
                }
                prev = temp;    // 更新 prev 为 dp[i-1][j]
            }
        }
        return dp[text2.size()];
    }
};