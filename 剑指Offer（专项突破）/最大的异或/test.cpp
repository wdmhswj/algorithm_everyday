#include "../../utils/utils.h"


class Solution {
public:
    int findMaximumXOR(std::vector<int>& nums) {
        int ret = INT_MIN;
        for (size_t i=0; i<nums.size(); ++i) {
            for (size_t j=i; j<nums.size(); ++j) {
                ret = std::max(ret, nums[i]^nums[j]);
            }
        }
        return ret;
    }

    int findMaximumXOR(std::vector<int>& nums) {
        int ret = 0;
        for (int k=30; k>=0; --k) {
            std::unordered_set<int> seen;
            for (int num: nums) {
                seen.insert(num>>k);    // 保留从最高位到第k位的部分
            }

            int next_expected_ret = ret*2 + 1;  // 第k位置为1
            bool found = false;
            for (int num: nums) {
                if (seen.count(next_expected_ret^(num>>k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                ret = next_expected_ret;
            } else {
                ret = next_expected_ret-1;
            }
        }
        return ret;
    }

};