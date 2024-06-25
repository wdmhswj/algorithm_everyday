#include <vector>
using std::vector;

class Solution1 {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size()==1) {
            return 0;
        }
        int size = nums.size();
        int max_index = 0;
        int count = 0;
        for (int i=0; i<=max_index && i<size; ++i) {
            if (nums[i]+i>max_index) {
                max_index = nums[i]+i;
                ++count;
            }
            if (max_index>=size-1) {
                break;
            }
        }
        return count;
    }
};
class Solution2 {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size()==1) {
            return 0;
        }
        int size = nums.size();
        int curDis = 0, nextDis = 0;
        int count = 0;
        for (int i=0; i<size; ++i) {
            if (nums[i]+i>nextDis) {
                nextDis = nums[i]+i;
            }
            if (i==curDis) {
                ++count;
                curDis = nextDis;
                if (nextDis>=size-1) {
                    break;
                }
            }
           
        }
        return count;
    }
};