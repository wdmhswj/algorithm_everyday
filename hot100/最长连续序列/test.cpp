#include "../../utils/utils.h"

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set;
        for (int num: nums) 
            num_set.insert(num);
        
        int ret = 0;
        for (int num: num_set) {
            if (!num_set.count(num-1)) {
                int cur = num;
                int len = 1;
                while (num_set.count(cur+1)) {
                    ++cur;
                    ++len;
                }
                ret = std::max(ret, len);
            }
        }
        return ret;
    }
};