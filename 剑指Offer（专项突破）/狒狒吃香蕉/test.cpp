#include "../../utils/utils.h"

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        auto it = std::max_element(piles.begin(), piles.end());
        if (it==piles.end()) return 0;
        int left = 1;
        int right = *it;
        while (left<right) {
            int mid = left + (right-left)/2;
            int sum = 0;
            for (int p: piles) {
                sum += (p+mid-1)/mid;
            }
            if (sum<=h)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};