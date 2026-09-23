
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> odd_prefix(n+1, 0);
        std::vector<int> even_prefix(n+1, 0);
        int sum_odd = 0;
        int sum_even = 0;
        for (int i=0; i<n; ++i) {
            if (i%2==0) {
                sum_even += nums[i];
                even_prefix[i+1] = sum_even;
                odd_prefix[i+1] = odd_prefix[i];
            } else {
                sum_odd += nums[i];
                odd_prefix[i+1] = sum_odd;
                even_prefix[i+1] = even_prefix[i];
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            sum_odd = (even_prefix[n]-even_prefix[i+1]) + odd_prefix[i];
            sum_even = (odd_prefix[n]-odd_prefix[i+1]) + even_prefix[i];
            if (sum_odd==sum_even) ++res; 
        }
        return res;
    }

    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int total_even = 0, total_odd = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) total_even += nums[i];
            else total_odd += nums[i];
        }

        int left_even = 0, left_odd = 0;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            // 右侧原奇偶和
            int right_even = total_even - left_even - (i % 2 == 0 ? nums[i] : 0);
            int right_odd  = total_odd  - left_odd  - (i % 2 == 1 ? nums[i] : 0);

            // 删除 i 后的新奇偶和
            int new_odd  = left_odd  + right_even;  // 左侧奇数 + 右侧偶数（翻转后变奇数）
            int new_even = left_even + right_odd;   // 左侧偶数 + 右侧奇数（翻转后变偶数）

            if (new_odd == new_even) ++res;

            // 更新左侧和
            if (i % 2 == 0) left_even += nums[i];
            else left_odd += nums[i];
        }

        return res;
    }
};


int main() {
    
    return 0;
}