#include "../../../utils/utils.h"

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int res = 0;
        int cur = 0;
        for (int num: nums) {
            if (num != 1) {
                res = std::max(res, cur);
                cur = 0;
            } else {
                ++cur;
            }
        }
        res = std::max(res, cur);
        return res;
    }
};