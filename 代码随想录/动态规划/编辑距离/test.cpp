#include <string>
#include <vector>


using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size(), size2=word2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        for(int i=1; i<=size1; ++i) {
            dp[i][0]=i;
        }
        for(int i=1; i<=size2; ++i) {
            dp[0][i]=i;
        }
        for(int i=1; i<=size1; ++i) {
            for(int j=1; j<=size2; ++j) {
                if (word1[i-1]==word2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
                }
            }
        }
        return dp[size1][size2];
    }

    // 优化版
    int minDistance1(string word1, string word2) {
        int size1=word1.size(), size2=word2.size();
        
        vector<int> dp(size2+1, 0);
        // for(int i=1; i<=size1; ++i) {
        //     dp[i][0]=i;
        // }
        for(int i=1; i<=size2; ++i) {
            dp[i]=i;
        }
        for(int i=1; i<=size1; ++i) {
            int pre=i-1;    // dp[i-1][0]=i-1
            dp[0]=i;    // dp[i][0]=i
            for(int j=1; j<=size2; ++j) {
                int tmp=dp[j];
                if (word1[i-1]==word2[j-1]) {
                    dp[j]=pre;
                } else {
                    dp[j]=std::min({pre, dp[j], dp[j-1]})+1;
                }
                pre=tmp;
            }
        }
        return dp[size2];
    }
};