#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;    // 奇数数组
        vector<int> even;   // 偶数数组
        for(const int& num: nums)
        {
            if(num%2==0)
                even.push_back(num);
            else
                odd.push_back(num);
        }

        vector<int> res(nums.size());
        // 偶数位置
        for(int i=0,j=0; i<nums.size(); i+=2,++j)
        {   
            res[i] = even[j];
        }
        // 奇数位置
        for(int i=1,j=0; i<nums.size(); i+=2,++j)
        {   
            res[i] = odd[j];
        }
        return res;
    }
    vector<int> sortArrayByParityII2(vector<int>& nums) {

        int i=0, j=1;
        const int n = nums.size();
        while (i<n && j<n) {
            while (i<n && nums[i]%2==0) {
                i+=2;
            }
            while (j<n && nums[j]%2==1) {
                j+=2;
            }
            if(i<n && j<n)
                std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};