#include "../../utils/utils.h"


class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        for (int i=0; i<arr.size()-1; ++i) {
            if (arr[i]>arr[i+1]) return i;
        }
        return arr.size()-1;
    }

    int peakIndexInMountainArray(std::vector<int>& arr) {
        int l=1, r=arr.size()-2;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (arr[mid]<arr[mid+1]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};