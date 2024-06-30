#include <algorithm>
#include <vector>

using std::vector;


class Solution {
private:
    static bool cmp(const vector<int>& l, const vector<int>& r) {
        return l[0]<r[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        int res = 1;
        std::sort(points.begin(), points.end(), cmp);
        int bound_r=points[0][1];
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0]>bound_r) {
                ++res;
                bound_r = points[i][1];     // 更新重叠的右边界
            } else {
                bound_r = points[i][1]<bound_r ? points[i][1] : bound_r;
            }
        }
        return res;
    }
};