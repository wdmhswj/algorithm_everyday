#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;

void print2Vec(const vector<vector<int>>& intervals){
    for (auto& vec : intervals) {
        for(auto& num: vec) {
            std::cout<<num<<" ";
        }
        std::cout<<std::endl;
    }
}

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

    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        // 先排序
        std::sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0]<r[0];
        });

        print2Vec(intervals);

        int res = 0;   
        int right_bound = intervals[0][1];  // 当前已遍历的无重叠的intervals的右边界
        for(int i=1; i<intervals.size(); ++i) {
            // 判断是否重叠
            if (intervals[i][0]<right_bound) {    // 有重叠(要用有边界而不是上一个index的有边界！！！)
                ++res;
                if (intervals[i][1]<right_bound) {  // 右边界有更小的选择
                    right_bound=intervals[i][1];
                }
            } else {
                right_bound=intervals[i][1];
            }
        }
        return res;
    }
};


int main(){
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };
    Solution s;
    std::cout<<s.eraseOverlapIntervals1(intervals);

}