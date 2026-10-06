
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int n = nums.size();
        if (n<=1) return 0;
        std::sort(nums.begin(), nums.end());

        int res = 0;
        int step = 0;
        int cnt = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i] != nums[i-1]) {
                res += cnt * step; // 同值元素数 * 台阶数
                ++step;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        res += cnt * step;

        return res;

    }
};

int main() {
    
    return 0;
}