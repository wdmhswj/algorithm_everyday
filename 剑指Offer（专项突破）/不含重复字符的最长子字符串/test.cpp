#include "../../utils/utils.h"


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int n = s.size();
        std::unordered_map<char, int> charIndexMap; // 记录字符上次出现的位置
        int ret = 0;
        for (int left=0, right=0; right<n; ++right)
        {
            const char c = s[right];
            if (charIndexMap.count(c) && charIndexMap[c] >= left)
            {
                left = charIndexMap[c] + 1;
            }
            charIndexMap[c] = right;
            ret = std::max(ret, right - left + 1);
        }
        return ret;
    }

    int lengthOfLongestSubstring_1(std::string s) {
        const int n = s.size();
        // 用 -1 表示没出现过
        std::array<int, 256> last;
        last.fill(-1);

        int ret = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            ret = std::max(ret, right - left + 1);
        }
        return ret;
    }
};