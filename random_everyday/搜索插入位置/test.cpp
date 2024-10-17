#include <vector>

using std::vector;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L=0, R=nums.size()-1;
        int m=-1;
        while(L<=R) {
            m = L + (R-L)/2;
            if(target==nums[m]){
                return m;
            }else if(target<nums[m]){
                R = m-1;
            }else{
                L = m+1;
            }
            
        }
        if(target>nums[m])
            return m+1;
        else
            return m; 

    }
};