#include <vector>
using std::vector;

class Solution {
private:
    bool maxIndex(int p, int ) {
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty() || nums.size()==1) {
            return true;
        }
        int size = nums.size();
        int max_index = nums[0];
        for (int i=0; i<=max_index && i<size; ++i) {
            if (nums[i]+i>max_index) {
                max_index = nums[i]+i;
            }
            if (max_index>=size-1) {
                return true;
            }
        }
        return false;

    }
};