#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int last_start = intervals[0][0];
        int last_end = intervals[0][1];

        std::vector<std::vector<int>> ret;
        for (int i=1; i<intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start<=last_end) {
                last_end = std::max(last_end, end);
            } else {
                ret.push_back({last_start, last_end});
                last_start = start;
                last_end = end;
            }
        }
        ret.push_back({last_start, last_end});
        return ret;
    }
};