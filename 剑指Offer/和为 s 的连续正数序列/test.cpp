#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::vector<int>> fileCombination(int target) {
        if (target < 2) return {};
        int l = 1, r = 2;
        std::vector<std::vector<int>> rt;
        while (l<r)
        {
            int sum = (r+l) * (r-l+1) / 2;
            if (sum == target)
            {
                // std::vector<int> tmp(r-l+1);
                // std::iota(tmp.begin(), tmp.end(), l);
                // rt.push_back(std::move(tmp));
                rt.emplace_back(r-l+1);
                std::iota(rt.back().begin(), rt.back().end(), l);
                ++l;
            } else if (sum < target)
            {
                ++r;
            } else
            {
                ++l;
            }
        }
        return rt;
    }
};