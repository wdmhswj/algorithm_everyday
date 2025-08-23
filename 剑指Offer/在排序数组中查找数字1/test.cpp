#include "../../utils/utils.h"

class Solution {
public:
    int countTarget(std::vector<int>& scores, int target) {
        auto l = std::lower_bound(scores.begin(), scores.end(), target);
        auto r = std::upper_bound(scores.begin(), scores.end(), target);
        return r-l;
    }
};