#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        if (n<=1) return intervals;

        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) -> bool {
            return a[0]<b[0] || a[0]==b[0]&&a[1]<b[1]; // 严格弱序
        };
        std::sort(intervals.begin(), intervals.end(), cmp);
        std::vector<std::vector<int>> res;
        int bgn = intervals[0][0], end = intervals[0][1];
        for (int i=1; i<n; ++i) {
            if (end < intervals[i][0]) {
                res.push_back({bgn, end});
                bgn = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = std::max(end, intervals[i][1]);
            }
        }
        res.push_back({bgn, end});
        return res;
        
    }
};

int main() {
    
    return 0;
}