#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> res;
        res.reserve(2*n);
        for (int i=0; i<n; ++i) {
            res.emplace_back(nums[i]);
            res.emplace_back(nums[i+n]);
        }
        return res;
    }   

    std::vector<int> shuffle(std::vector<int>& nums, int n) {

        const int M = 10000;
        
        // 合并信息
        for (int i = 0; i < n; i++) {
            nums[i] += nums[i+n] * M;
        }


        // 重新排列
        for (int i = n-1; i >= 0; i--) {

            int x = nums[i] % M;
            int y = nums[i] / M;

            nums[2*i] = x;
            nums[2*i+1] = y;
        }

        return nums;
    }

};