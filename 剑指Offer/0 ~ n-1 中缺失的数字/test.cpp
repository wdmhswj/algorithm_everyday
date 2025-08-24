#include "../../utils/utils.h"

class Solution {
public:
    int takeAttendance(std::vector<int>& records) {
        int l = 0, r = records.size()-1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (records[mid]==mid) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
};