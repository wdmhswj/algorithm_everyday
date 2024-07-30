#include <algorithm>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        if (heights.size()==1) {
            return heights[0];
        }
        stack<int> st;

        st.push(0);
        int max=heights[0];
        for(int i=1; i<heights.size(); ++i) {
            if (heights[i]==st.top()) {
                continue;
            }else if(heights[i]<st.top()) {
                st.push(i);
            }else{
                int right_index=-1;
                int min_index=st.top();
                while (!st.empty()) {
                    right_index=st.top();
                    st.pop();
                }
                int size=(i-right_index+1)*heights[min_index];
                    max=std::max(max, size);
            }
        }
        return max;
    }
    int largestRectangleArea1(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        if (heights.size()==1) {
            return heights[0];
        }
        stack<int> st;

        // 首尾加0
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        st.push(0);
        int max=heights[0];
        for(int i=1; i<heights.size(); ++i) {
            if (heights[i]>heights[st.top()]) {
                st.push(i);
            }else if (heights[i]>heights[st.top()]) {
                st.pop();
                st.push(i);
            }else {
                while (!st.empty() && heights[i]<heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int right=i;
                        int left=st.top();
                        int w=right-left-1;
                        int h=heights[mid];
                        max=std::max(max, h*w);
                    }
                    
                }
                st.push(i);
            }
        }
        return max;
    }
    int largestRectangleArea2(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        if (heights.size()==1) {
            return heights[0];
        }
        stack<int> st;

        // 首尾加0
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        st.push(0);
        int max=heights[0];
        for(int i=1; i<heights.size(); ++i) {

            while (!st.empty() && heights[i]<heights[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    max=std::max(max, heights[mid]*(i-st.top()-1));
                }
            }
            st.push(i);
        }
        return max;
    }
};