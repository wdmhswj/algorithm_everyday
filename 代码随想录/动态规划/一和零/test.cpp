#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    int get0num(const string& str) {
        int res=0;
        for(const char& c: str) {
            if (c=='0') {
                ++res;
            }
        }
        return res;
    }
    int get1num(const string& str) {
        int res=0;
        for(const char& c: str) {
            if (c=='1') {
                ++res;
            }
        }
        return res;
    }
public:

    // v1
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty()) {
            return 0;
        }
        // 获取每个str中0和1的个数
        vector<vector<int>> count(strs.size(), vector<int>(2, 0));
        for (int i=0; i<strs.size();++i) {
            count[i][0] = get0num(strs[i]);
            count[i][1] = get1num(strs[i]);
        }

        // for(auto& vec: count) {
        //     for(auto i: vec){
        //         std::cout<<i<<" ";
        //     }
        //     std::cout<<std::endl;
        // }

        // dp数组
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int k=0; k<strs.size(); ++k) {
            for(int i=m; i>=count[k][0]; --i) {
                for (int j=n; j>=count[k][1]; --j) {
                    dp[i][j] = std::max(dp[i][j], dp[i-count[k][0]][j-count[k][1]]+1);
                }
            }
        }
        return dp[m][n];
    }
    // v2
    int findMaxForm1(vector<string>& strs, int m, int n) {
        if (strs.empty()) {
            return 0;
        }

        // dp数组
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int k=0; k<strs.size(); ++k) {
            int count_0=0, count_1=0;
            for(auto& c: strs[k]) {
                if (c=='0') {
                    count_0++;
                } else {
                    count_1++;
                }
            }
            for(int i=m; i>=count_0; --i) {
                for (int j=n; j>=count_1; --j) {
                    dp[i][j] = std::max(dp[i][j], dp[i-count_0][j-count_1]+1);
                }
            }
        }
        return dp[m][n];
    }
};


int main() {

    vector<string> strs = {"10","0001","111001","1","0"};

    Solution s;
    std::cout<<s.findMaxForm(strs, 5, 3);
}