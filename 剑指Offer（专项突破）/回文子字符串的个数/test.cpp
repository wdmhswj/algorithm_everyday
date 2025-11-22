#include "../../utils/utils.h"
class Solution {
public:
    int countSubstrings(std::string s) {
        const int n = s.size();
        auto f = [&](int i, int j) -> int {
            int cnt = 0;
            for ( ; i>=0 && j<n && s[i]==s[j]; --i, ++j) {
                ++cnt;
            }
            return cnt;
        };

        int ret = 0;
        for (int i=0; i<n; ++i) {
            ret += f(i, i) + f(i, i+1); // i+1==n时，f(i, i+1)返回0
        }
        return ret;
    }

    // Manacher algorithm
    int countSubstrings_1(std::string s) {
        std::string s1 = "^#";
        for (const char& c: s) {
            s1.push_back(c);
            s1.push_back('#');
        }
        s1.push_back('$');
        const int n = s1.size();
        std::vector<int> palindrome_radis(n, 0);
        int pos = 0;
        int maxRight = 0;
        int ret = 0;
        for (int i=1; i<n-1; ++i) {
            if (maxRight>i)
                palindrome_radis[i] = std::min(maxRight-i, palindrome_radis[2*pos-i]);
            else 
                palindrome_radis[i] = 1;
            while (s1[i-palindrome_radis[i]] == s1[i+palindrome_radis[i]]) {
                ++palindrome_radis[i];
            }
            if (i+palindrome_radis[i] > maxRight) {
                maxRight = i+palindrome_radis[i];
                pos = i;
            }
            ret += palindrome_radis[i]/2;
        }
        return ret;
    }
};