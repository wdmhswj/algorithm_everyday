#include "../../utils/utils.h"

class Solution {
public:
    bool checkInclusion0(std::string s1, std::string s2) {
        const int m = s1.size();
        const int n = s2.size();
        if (m > n)
        {
            return false;
        }

        std::vector<int> cnt1(26, 0);
        std::vector<int> cnt2(26, 0);

        for (int i=0; i<m; ++i)
        {
            ++cnt1[s1[i]-'a'];
            ++cnt2[s2[i]-'a'];
        }

        if (cnt1 == cnt2)
        {
            return true;
        }

        for (int i=m; i<n; ++i)
        {
            ++cnt2[s2[i]-'a'];
            --cnt2[s2[i-m]-'a'];

            if (cnt1 == cnt2)
            {
                return true;
            }
        }
        return false;
    }


    bool checkInclusion(std::string s1, std::string s2) {
        const int m = s1.size();
        const int n = s2.size();
        if (m > n)
        {
            return false;
        }

        std::vector<int> cnt(26, 0);

        for (int i=0; i<m; ++i)
        {
            --cnt[s1[i]-'a'];
            ++cnt[s2[i]-'a'];
        }

        int diff = 0;   // 记录字符频次不同的字符个数
        for (const int c : cnt)
        {
            if (c != 0)
            {
                ++diff;
            }
        }

        if (diff == 0)
        {
            return true;
        }

        for (int i=m; i<n; ++i)
        {
            int a = s2[i - m] - 'a';
            int b = s2[i] - 'a';
            if (cnt[a]==0)
            {
                ++diff;
            }
            --cnt[a];
            if (cnt[a]==0)
            {
                --diff;
            }
            if (cnt[b]==0)
            {
                ++diff;
            }
            ++cnt[b];
            if (cnt[b]==0)
            {
                --diff;
            }
            if (diff == 0)
            {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    Solution sol;
    bool result = sol.checkInclusion(s1, s2);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}