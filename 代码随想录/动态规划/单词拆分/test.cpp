#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    bool endWith(const string& s, const string& word, int end) {
        for(int i=0; i<word.size(); ++i) {
            if (s[end-word.size()+i]!=word[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, false);
        dp[0]=true;

        // for(int i=0; i<wordDict.size(); ++i) {
        //     for(int j=wordDict[i].size(); j<=s.size(); ++j) {
        //         if (endWith(s, wordDict[i], j)) {
        //             dp[j] = dp[j]|| dp[j-wordDict[i].size()];
        //         }
        //     }
        // }

        for(int j=0; j<=s.size(); ++j) {
            for(int i=0; i<wordDict.size(); ++i) {
                if (j>=wordDict[i].size() && endWith(s, wordDict[i], j)) {
                    std::cout<<"wordDict["<<i<<"]="<<wordDict[i]<<std::endl;
                    std::cout<<"j="<<j<<std::endl;
                    std::cout<<"dp[j]="<<dp[j]<<"||"<<dp[j-wordDict[i].size()]<<std::endl;

                    dp[j]=dp[j] || dp[j-wordDict[i].size()];
                    
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution solution;

    vector<string> wordDict={"cats","dog","sand","and","cat"};
    string s="catsandog";
    solution.wordBreak(s, wordDict);
    return 0;
}