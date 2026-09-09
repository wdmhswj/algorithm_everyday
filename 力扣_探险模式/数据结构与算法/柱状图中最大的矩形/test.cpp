#include "../../../utils/utils.h"

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        const int n = heights.size();
        int res = 0;
        std::stack<int> stk; // 存储索引
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);

        for (int i=0; i<n; ++i) {
            while (!stk.empty() && heights[i]<heights[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i=n-1; i>=0; --i) {
            while (!stk.empty() && heights[i]<heights[stk.top()]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        for (int i=0; i<n; ++i) {
            res = std::max(res, heights[i]*(right[i]-left[i]-1));
        }
    
        return res;
    }


    int largestRectangleArea(std::vector<int>& heights) {
        const int n = heights.size();
        int res = 0;
        std::stack<int> stk; // 存储索引


        for (int i=0; i<=n; ++i) {
            int curHeight = (i==n) ? 0 : heights[i]; // 强制遍历结束时弹出所有剩余元素
            while (!stk.empty() && curHeight<heights[stk.top()]) {
                int h = heights[stk.top()]; // 栈顶元素为矩阵高度
                stk.pop();

                int leftIndex = stk.empty() ? -1 : stk.top(); // 新栈顶为左边界
                res = std::max(res, h*(i-leftIndex-1));
            }
            stk.push(i);
        }
        
    
        return res;
    }
};