#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) {
            return 1;
        }
        int p1 = 1, p2=1;
        const int n = nums.size();
        while (p1<n && p2<n) {
            if (nums[p1-1] == nums[p2]) {
                ++p2;
            }else {
                nums[p1]=nums[p2];
                ++p1;
                ++p2;
            }
        }
        return p1;
    }
    int removeDuplicates2(vector<int>& nums) {
        if (nums.size()==1) {
            return 1;
        }
        int p1 = 1, p2=1;
        const int n = nums.size();
        while (p1<n && p2<n) {
            if (nums[p1-1] != nums[p2]) {
                nums[p1]=nums[p2];
                ++p1;
            }
            ++p2;
        }
        return p1;
    }
};