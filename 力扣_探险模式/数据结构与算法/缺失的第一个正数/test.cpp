#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        std::vector<bool> cnt(n+1, false);
        for (int num: nums) {
            if (num>=0 && num<=n) {
                cnt[num] = true;
            }
        }
        for (int i=1; i<=n; ++i) {
            if (!cnt[i]) return i;
        }
        return n+1;
    }

    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int i=0; i<n; ++i) {
            while (1<=nums[i] && nums[i]<=n && nums[i] != nums[nums[i]-1]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<n; ++i) {
            if (nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};

int main() {
    
    return 0;
}