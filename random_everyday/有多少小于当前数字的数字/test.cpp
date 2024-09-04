#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <map>

using std::vector;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        std::map<int, int> map;
        vector<int> res(nums.size(), 0);
        // 记录有哪些数字
        for(const int& e: nums)
        {
            map[e]++;
        }
         for(auto it=map.begin(); it!=map.end(); ++it)
        {
            std::cout<<it->first<<": "<<it->second<<std::endl;
        }
        int count = 0;
        for(auto it = map.begin(); it!=map.end(); ++it)
        {
            for(int i=0; i<nums.size(); ++i) {
                if (nums[i]==it->first) {
                    // std::cout<<"nums["<<i<<"]="<<nums[i]<<" count="<<count<<std::endl;
                    res[i]=count;
                }
            }
            count += it->second;
        }
       
        
        // for(int i=0; i<res.size(); ++i)
        // {
        //     std::cout<<i<<": "<<res[i]<<std::endl;
        // }
        return res;
    }

    vector<int> smallerNumbersThanCurrent2(vector<int>& nums)
    {
        if (nums.empty()) {
            return {};
        }
        const int n = nums.size();
        // 记录每个元素的位置
        vector<std::pair<int, int>> pos;
        for(int i=0; i<n; ++i)
        {
            pos.push_back({nums[i], i});
        }
        // auto nums_copy = nums;
        std::sort(pos.begin(), pos.end());
        vector<int> res(n, 0);
        int pre = -1;    // 前一个元素的位置
        for(int i=0; i<n; i++)
        {
            if(pre==-1 || pos[i].first!=pos[i-1].first)
            {
                pre = i;
            }
            res[pos[i].second] = pre;
        }
        return res;
    }

    vector<int> smallerNumbersThanCurrent3(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return ret;
    }

};

int main()
{
    Solution s;
    vector<int> nums = {
        8,1,2,2,3
    };
    s.smallerNumbersThanCurrent(nums);

}