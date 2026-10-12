#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int n = arr.size();
        if (n < 3) return -1;
        int l = 0, r = n-1;
        
        while (l < r) {
            int mid = l + (r-l)/2;
            if (arr[mid] < arr[mid+1]) { // 递增
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main() {
    
    return 0;
}