#include "../../utils/utils.h"

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        const int m = s.size();
        const int n = t.size();
        if (m<n) return {};
        std::array<int, 52> need = {0};
        std::array<int, 52> window = {0};
        for (const char c: t)
        {
            ++need[c-'A'>=26 ? c-'a'+26 : c-'A'];   // 大写字母映射到0-25，小写字母映射到26-51
        }
        
        int minLen = INT_MAX;
        int start = 0;
        for (int l=0, r=0; r<m; ++r)
        {
            const char c = s[r];
            ++window[c-'A'>=26 ? c-'a'+26 : c-'A']; // 更新窗口字符计数
            while (check(need, window))
            {
                if (r-l+1<minLen)
                {
                    minLen = r-l+1;
                    start = l;
                }
                --window[s[l]-'A'>=26 ? s[l]-'a'+26 : s[l]-'A']; // 收缩左边界
                ++l;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);

    }

    bool check(const std::array<int, 52>& need, const std::array<int, 52>& window)
    {
        for (int i=0; i<52; ++i)
        {
            if (need[i]>window[i]) return false;
        }
        return true;
    }
};