#include "../../utils/utils.h"


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // 排除长度不等，或完全相同的情况
        const int m = s.size();
        const int n = t.size();
        if (m!=n || s==t)
            return false;
        
        std::array<int, 26> cnt{};  // 初始置零
        for (int i=0; i<m; ++i)
        {
            ++cnt[s[i]-'a'];
            --cnt[t[i]-'a'];
        }
        for (const int& e: cnt)
        {
            if (e!=0)
                return false;
        }
        return true;

    }
};