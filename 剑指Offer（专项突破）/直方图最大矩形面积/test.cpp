#include "../../utils/utils.h"

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        const int n = heights.size();
        int ret = 0;
        for (int i=0; i<n; ++i)
        {
            int min_height = INT_MAX;
            for (int j=i; j<n; ++j) {
                min_height = std::min(min_height, heights[j]);
                ret = std::max(ret, (j-i+1)*min_height);
            }
        }
        return ret;
    }

    int largestRectangleArea1(std::vector<int>& heights) {
        const int n = heights.size();
        std::stack<int> st;
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);
        for (int i=0; i<n; ++i)
        {
            while (!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i=n-1; i>=0; --i)
        {
            while (!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        int ret = 0;
        for (int i=0; i<n; ++i)
        {
            ret = std::max(ret, (right[i]-left[i]-1)*heights[i]);
        }
        return ret;
    }
};