#include <algorithm>
#include <stdexcept>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        // 先排序
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0]<r[0];
        });

        vector<vector<int>> res;    // 存储返回结果
        int start=intervals[0][0], end=intervals[0][1];
        for(int i=1; i<intervals.size(); ++i){
            // 是否重叠
            if(intervals[i][0]<=end) {  // 重叠
                // if (intervals[i][1]>end) {
                //     end=intervals[i][1];
                // }
                end = std::max(intervals[i][1], end);
            } else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};