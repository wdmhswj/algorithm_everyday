#include <vector>

using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k%n;
        // 暂存后k个
        vector<int> temp(nums.end()-k, nums.end());
        // 前n-k个从后先前向右移动k
        for(int i=n-1; i>n-1-(n-k); --i)
        {
            nums[i]=nums[i-k];
        }
        // 后k个移动
        for(int i=0; i<k; ++i)
        {
            nums[i+k] = temp[i];
        }
    }
};