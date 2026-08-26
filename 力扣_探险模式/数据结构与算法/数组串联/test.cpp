#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> res(2*n, 0);
        for (int i=0; i<n; ++i) {
            res[i] = nums[i];
            res[i+n] = nums[i];
        }
        return res;
    }


    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> res;
        res.reserve(2*nums.size());
        res.insert(res.end(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};