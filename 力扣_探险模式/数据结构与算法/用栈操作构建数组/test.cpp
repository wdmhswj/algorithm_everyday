#include "../../../utils/utils.h"


class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> res;
        int cur = 1;
        for (int num: target) {
            while (cur != num) {
                ++cur;
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            ++cur;
        }

        return res;
    }
};