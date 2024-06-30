#include <algorithm>
#include <vector>
using std::vector;

class Solution {
private:
    static bool cmp(const vector<int>& l, const vector<int>& r) {
        return l[0]<r[0] || l[0]==r[0]&&l[1]<r[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(), cmp);
        int res=0;
        int last_right_bound = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0]>=last_right_bound) {
                last_right_bound = intervals[i][1];
            } else {
                ++res;
                last_right_bound = intervals[i][1]<last_right_bound ? intervals[i][1] : last_right_bound;   // 使得右边界尽可能靠左
            }

        }
        return res;
    }
};