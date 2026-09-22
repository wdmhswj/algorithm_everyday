#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int res = 0;
        if (sum%p == 0) return res;
        const int n = nums.size();
        while (++res < n) {
            long long sub_sum = std::accumulate(nums.begin(), nums.begin()+res, 0);
            if ((sum-sub_sum)%p == 0) return res;
            for (int i=1; i+res<=n; ++i) {
                sub_sum -= nums[i-1];
                sub_sum += nums[i+res-1];
                if ((sum-sub_sum)%p == 0) return res;
            }
        }
        return -1;
    }

    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        std::vector<int> s(n+1, 0);
        for (int i=0; i<n; ++i) {
            s[i+1] = (s[i] + nums[i])%p;
        }

        int x = s[n];
        std::unordered_map<int, int> last;
        int res = n;
        for (int i=0; i<=n; ++i) {
            last[s[i]] = i;
            auto it = last.find((s[i]-x+p)%p);
            if (it != last.end()) {
                res = std::min(res, i-it->second);
            }
        }
        return res<n ? res : -1;
    }
};

int main() {
    
    return 0;
}