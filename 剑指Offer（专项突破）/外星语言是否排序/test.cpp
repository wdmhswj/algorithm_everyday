#include "../../utils/utils.h"

class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        // 用哈希记录字典中不同字母的顺序
        std::array<int, 26> index;
        for (int i=0; i<order.size(); ++i)
            index[order[i]-'a'] = i;
        
        for (int i=0; i<words.size()-1; ++i)
        {
            const int l_sz = words[i].size();
            const int r_sz = words[i+1].size();
            for (int j=0; j<std::max(l_sz, r_sz); ++j)
            {
                int l_idx = j>=l_sz ? -1 : index[words[i][j]-'a'];
                int r_idx = j>=r_sz ? -1 : index[words[i+1][j]-'a'];
                if (l_idx>r_idx) return false;
                if (l_idx<r_idx) break;
            }
        }
        return true;
    }
};