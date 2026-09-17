#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int n = s.size();
        if (n<=1) return false;
        int bgn=0, end=1;
        bool res = true;
        for (; end<=n/2; ++end) {
            int len = end-bgn;
            if (n%len != 0) continue;
            std::cout << "[" << bgn << " ," << end << ")\n"; 
            res = true;
            for (int i=end; i+len<=n; i+=len) {
                for (int j=0; j<len; ++j) {
                    if (s[bgn+j] != s[i+j]) {
                        res = false;
                        break;
                    }
                }
                if (res == false) break;
            }
            if (res == true) break;

        }
        return res;
    }

    bool repeatedSubstringPattern_1(string s) {
        const int n = s.size();
        if (n<=1) return false;
        bool res = true;
        for (int len = 1; len<=n/2; ++len) {
            if (n%len != 0) continue;
            res = true;
            for (int i=len; i<n; i+=len) {
                if (s.compare(0, len, s, i, len) != 0) {
                    res = false;
                }
            }
            if (res) return true;
        }
        return false;
    }

    bool repeatedSubstringPattern_1(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};

int main() {
    std::string s = "aabaaba";
    Solution sol;
    std::cout << sol.repeatedSubstringPattern(s) << std::endl;

    return 0;
}