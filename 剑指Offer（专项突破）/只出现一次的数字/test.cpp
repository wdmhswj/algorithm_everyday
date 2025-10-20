#include "../../utils/utils.h"

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int,int> count;
        for (const int& e: nums)
        {
            ++count[e];
        }
        for (const auto& e: count)
        {
            if (e.second==1) return e.first;
        }
        return -1;
    }

    int singleNumber1(std::vector<int>& nums) {
        int rt = 0;
        for (int i = 0; i<32; ++i)
        {
            int cnt = 0;
            for (const int& e: nums)
            {
                cnt += (e>>i)&1;
            }
            if (cnt%3 == 1)
            {
                rt |= (1<<i);
            }
        }
        return rt;
    }
};