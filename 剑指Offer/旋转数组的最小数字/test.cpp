#include "../../utils/utils.h"

class Solution {
public:
    int inventoryManagement(std::vector<int>& stock) {
        int l=0, r=stock.size()-1;
        if (r==-1) return -1;
        int mid = -1;
        while (l<r) {
            mid = l + (r-l)/2;
            if (stock[mid] < stock[r]) {
                r = mid;
            } else if (stock[mid] > stock[r]) {
                l = mid + 1;
            } else {
                --r;
            }
        }
        return stock[l];
    }
};