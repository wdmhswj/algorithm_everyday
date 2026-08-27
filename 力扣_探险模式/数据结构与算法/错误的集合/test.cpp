#include "../../../utils/utils.h"


class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::unordered_map<int, int> count;

        std::vector<int> res;
        for (int i=0; i<nums.size(); ++i) {
            ++count[nums[i]];
            if (count[nums[i]] == 2) res.push_back(nums[i]);
        }

        for (int i=1; i<=nums.size(); ++i) {
            if (!count.count(i)) {
                res.push_back(i);
                break;
            }
        }
        return res;

    }

    std::vector<int> findErrorNums(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> cnt(n+1, 0);

        
        for (int num: nums) {
            ++cnt[num];
        }

        int dup = -1, missing = -1;
        for (int i=1; i<=n; ++i) {  
            if (cnt[i]==2) {
                dup = i;
            } else if (cnt[i]==0) {
                missing = i;
            }
        }
        return {dup, missing};

    }


    std::vector<int> findErrorNums(std::vector<int>& nums) {
        const int n = nums.size();
 
        int dup = -1, missing = -1;
        for (int i=0; i<n; ++i) {  
            int idx = std::abs(nums[i])-1;
            if (nums[idx] < 0) {
                dup = std::abs(nums[i]);
            } else {
                nums[idx] = -nums[idx];
            }
        }

        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        return {dup, missing};

    }
};