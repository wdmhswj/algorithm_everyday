#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        // 二分法
        int L=0, R=nums.size()-1;
        int m = -1;
        while (L<=R) {
            m = L + (R-L)/2;
            if(nums[m]==target) {
                break;
            }else if (nums[m]<target) {
                L = m+1;
            }else {
                R = m-1;
            }
        }
        if (L>R) {  // 没找到目标元素
            return {-1, -1};
        }
        L=m;
        for(int i=m-1; i>=0; --i)
        {
            if (nums[i]<nums[m]) {
                break;
            }
            L=i;
        }
        R=m;
        for(int i=m+1; i<nums.size(); ++i)
        {
            if (nums[i]>nums[m]) {
                break;
            }
            R=i;
        }
        return {L, R};
    }
};