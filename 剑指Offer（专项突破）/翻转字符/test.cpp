#include "../../utils/utils.h"

class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        const int n = s.size();
        int left0=0, right0=0;
        for (char c: s) {
            right0 += (c=='0');
        }
        int res = std::min(right0, n-right0);
        for (int i=0; i<n; ++i) {
            int x = s[i]=='0';
            right0 -= x;
            left0 += x;
            res = std::min(res, i+1-left0+right0);
        }
        return res;   
    }
};