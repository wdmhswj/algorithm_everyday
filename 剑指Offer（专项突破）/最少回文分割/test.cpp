#include "../../utils/utils.h"

class Solution {
public:
    int minCut(std::string s) {
        const int n = s.size();
        std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                isPalindrome[i][j] = this->_isPalindrome(s, i, j);
            }
        }
        std::vector<int> dp(n, 0);
        for (int i=0; i<n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // 最坏情况，每个字符都需要分割
                for (int j=1; j<=i; ++j) {
                    if (isPalindrome[j][i]) {
                        dp[i] = std::min(dp[i], dp[j-1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }


    int minCut_1(std::string s) {
        const int n = s.size();
        std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
        for (int len=1; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j=i+len-1;
                if (s[i] == s[j]) {
                    if (len <= 3) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    }
                }
            }
        }
        

        std::vector<int> dp(n, 0);
        for (int i=0; i<n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // 最坏情况，每个字符都需要分割
                for (int j=1; j<=i; ++j) {
                    if (isPalindrome[j][i]) {
                        dp[i] = std::min(dp[i], dp[j-1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }

private:
    bool _isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};