#include <unordered_map>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

    int majorityElement2(vector<int>& nums) {
        std::unordered_map<int, int> map;

        int majority = 0, cnt = 0;
        for(const int& num: nums)
        {
            map[num]++;
            if(map[num]>cnt){
                majority = num;
                cnt = map[num];
            }
        }
        return majority;
    }
    
};