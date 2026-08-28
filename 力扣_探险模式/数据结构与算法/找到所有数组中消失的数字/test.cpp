#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        const int n = nums.size();
        for (int i=0; i<n; ++i) {
            int idx = std::abs(nums[i])-1;
            if (nums[idx]>0) {
                nums[idx] = -nums[idx];
            }
        }

        std::vector<int> res;
        for (int i=0; i<n; ++i) {
            if (nums[i]>0) res.push_back(i+1);
        }
        return res;
    }

    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        const int n = nums.size();
        for (int i=0; i<n; ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
            std::swap(nums[i], nums[nums[i]-1]);
        }

        std::vector<int> res;
        for (int i=0; i<n; ++i) {
            if (nums[i] != i+1) res.push_back(i+1);
        }
        return res;
    }
};