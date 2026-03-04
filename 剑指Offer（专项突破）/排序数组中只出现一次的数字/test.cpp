#include "../../utils/utils.h"


class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        for (int i=0; i<nums.size(); i+=2) {
            if (i+1<nums.size()) {
                if (nums[i]!=nums[i+1])
                    return nums[i];
            } else {
                return nums[i];
            }
        }
        return -1;
    }

    int singleNonDuplicate(std::vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (nums[mid] != nums[mid^1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return nums[l];
    }
};