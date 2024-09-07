#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]==0) ++count;
            else{
                nums[i-count] = nums[i];    // 前移
            }
        }
        for(int i=nums.size()-count; i<nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};