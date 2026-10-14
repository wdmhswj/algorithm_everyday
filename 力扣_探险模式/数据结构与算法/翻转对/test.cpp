
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        if (n<=1) return 0;
        
        return _reversePairs(nums, 0, n);
    }
private:
    int _reversePairs(std::vector<int>& nums, int bgn, int end) {
        if (end-bgn<=1) return 0;
        int mid = bgn + (end-bgn)/2;
        int left_pairs = _reversePairs(nums, bgn, mid);
        int right_pairs = _reversePairs(nums, mid, end);
        int res = left_pairs + right_pairs;
        int i=bgn, j=mid;
        while (i<mid) {
            while (j<end && static_cast<long long>(nums[i]) > 2*static_cast<long long>(nums[j])) ++j;
            res += (j-mid);
            ++i;
        }
        std::vector<int> sorted(end-bgn, 0);
        int p1 = bgn, p2 = mid, p = 0;
        while (p1<mid || p2<end) {
            if (p1>=mid) {
                sorted[p++] = nums[p2++];
            } else if (p2>=end) {
                sorted[p++] = nums[p1++];
            } else {
                if (nums[p1]<=nums[p2]) {
                    sorted[p++] = nums[p1++];
                } else {
                    sorted[p++] = nums[p2++];
                }
            }
        }

        for (int i=0; i<sorted.size(); ++i) {
            nums[bgn+i] = sorted[i];
        }
        return res;
    }
};

int main() {
    
    return 0;
}