#include "../../utils/utils.h"

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        int ret = 0;
        const int n = words.size();
        std::vector<int> counters(n, 0);
        for (int i=0; i<n; ++i)
        {
            for (const char& c: words[i])
            {
                counters[i] |= (1 << (c-'a'));
            }
        }

        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if ((counters[i] & counters[j])==0)
                {
                    ret = std::max(ret, static_cast<int>(words[i].size()*words[j].size()));
                }
            }
        }

        return ret;
    }
};