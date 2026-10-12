#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n<1) return -1;
        int l = 0, r = n-1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (target==nums[mid]) return mid;
            else if (target<nums[mid]) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}