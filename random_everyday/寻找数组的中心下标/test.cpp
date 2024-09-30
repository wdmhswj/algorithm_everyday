#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 从中间开始
        const int len = nums.size();
        // int middle = len/2;
        int left_sum = 0;
        int right_sum = 0;
        int cur = 0;
        while(cur>=0 && cur<len)
        {
            // 计算左和与右和
            left_sum = calculateSum(0, cur, nums);
            right_sum = calculateSum(cur+1, len, nums);
            if (left_sum==right_sum) {
                return cur;
            } else if (left_sum<right_sum) {
                int add = 0;
                int i=cur;
                do {
                    ++i;
                    if(i>=len) break;
                    add += nums[i]+nums[i-1];
                }while (add<=0);
                if(i>=len) return -1;
                cur = i;
            } else {
                int add = nums[cur];
                int i=cur;
                do {
                    ++i;
                    if(i>=len) break;
                    add += nums[i]+nums[i-1];
                }while (add>=0);
                if(i>=len) return -1;
                cur = i;
            }
        }
        return -1;

    }
    int pivotIndex2(vector<int>& nums) {
        // 从中间开始
        const int len = nums.size();
        const int sum = calculateSum(0, len, nums);
        int left_sum = 0;
        // int right_sum = 0;
        for(int i=0; i<len; i++)
        {
            if(left_sum == sum-nums[i]-left_sum)
                return i;
            left_sum+=nums[i];
        }
        return -1;

    }
private:
    int calculateSum(const int& begin, const int& end, const vector<int>& nums)
    {
        int res = 0;
        for(int i=begin; i<end; i++)
        {
            res+=nums[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    

    vector<vector<int>> numss = {
        {1,7,3,6,5,6},
        {1,2,3},
        {2,1,-1},
        {-1,-1,-1,-1},
        {-1,-1,0,1,0,-1},
    };
    for(auto& nums: numss)
    {
        std::cout<<s.pivotIndex2(nums)<<std::endl;

    }
    
    return 0;
}