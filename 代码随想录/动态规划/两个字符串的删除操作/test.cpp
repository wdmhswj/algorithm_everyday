#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size(), size2=word2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));

        int max=0;
        for(int i=1; i<=size1; ++i) {
            for(int j=1; j<=size2; ++j) {
                if (word1[i-1]==word2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                } else {
                    dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]);
                }
                max=std::max(max, dp[i][j]);
            }
        }
        return size1-max+size2-max;
    }

    // 优化版（滚动数组）
    int minDistance1(string word1, string word2) {

        if (word1.size()<word2.size()) {
            std::swap(word1, word2);
        }
        int size1=word1.size(), size2=word2.size();
        

        vector<int> dp(size2+1, 0);
        int max=0;
        for(int i=1; i<=size1; ++i) {
            int pre=0;
            for(int j=1; j<=size2; ++j) {
                int tmp=dp[j];
                if (word1[i-1]==word2[j-1]) {
                    dp[j]=pre+1;
                } else {
                    dp[j]=std::max(dp[j], dp[j-1]);
                }
                max=std::max(max, dp[j]);
                pre=tmp;
            }
        }
        return size1-max+size2-max;
    }
};