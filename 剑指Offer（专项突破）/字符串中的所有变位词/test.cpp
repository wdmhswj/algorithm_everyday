#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        const int n = s.size();
        const int m = p.size();
        if (n < m) {
            return {};
        }

        std::vector<int> cnt(26, 0);

        for (int i=0; i<m; ++i) {
            ++cnt[p[i]-'a'];
            --cnt[s[i]-'a'];
        }

        int diff = 0;
        std::vector<int> ret;
        for (int c: cnt) {
            if (c!=0) {
                ++diff;
            }
        }
        if (diff==0) {
            ret.push_back(0);
        }
        
        for (int i=m; i<n; ++i)
        {
            int pop = s[i-m]-'a';
            int push = s[i]-'a';
            if (cnt[push]==0) {
                ++diff;
            }
            --cnt[push];
            if (cnt[push]==0) {
                --diff;
            }
            if (cnt[pop]==0) {
                ++diff;
            }
            ++cnt[pop];
            if (cnt[pop]==0) {
                --diff;
            }
            if (diff==0) {
                ret.push_back(i-m+1);
            }
        }
        return ret;
    }
};