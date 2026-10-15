
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n<3) return -1;
        std::sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[3];
        for (int i=0; i+2<n; ++i) {
            int j = i+1;
            int k = n-1;
            while (j<k) {
                int total = nums[i]+nums[j]+nums[k];
                if (std::abs(total-target) < std::abs(res-target)) res = total;
                if (total<target) ++j;
                else if (total>target) --k;
                else return target;
            }
        }
        return res;
    }
};


int main() {
    
    return 0;
}