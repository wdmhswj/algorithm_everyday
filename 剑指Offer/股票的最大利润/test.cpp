#include "../../utils/utils.h"



class Solution {
public:
    int bestTiming(std::vector<int>& prices) {
        int rt = 0;
        int min = INT_MAX;
        for (const int& e: prices)
        {
            min = std::min(min, e);
            rt = std::max(rt, e-min);
        }
        return rt;
    }
};