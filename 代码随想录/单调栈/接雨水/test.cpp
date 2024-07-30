#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <thread> // 包含线程库
#include <chrono> // 包含时间库
#include "../../../utils/printH.h"
using std::vector;
using std::stack;

class Solution {

public:
    // 单调栈
   int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n=height.size();
        stack<int> st;
        st.push(0);
        int res=0;
        for(int i=1; i<n; ++i) {
            if (height[i]==height[st.top()]) {
                st.pop();
            } else{
                while (!st.empty() && height[i]>height[st.top()]) {
                int mid=st.top();
                st.pop();
                if (!st.empty()) {
                    int h=std::min(height[st.top()], height[i])-height[mid];
                    int w=i-st.top()-1;
                    res+=w*h;
                }
                
            }
            // st.push(i);
            }
            

           st.push(i);
        }
       return res;
    }

    // 暴力求解
    int trap1(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n=height.size();
        int res=0;
        for(int i=1; i<n-1; ++i) {
            int r_max_height=height[i];
            int l_max_height=height[i];
            for(int j=i+1; j<n; ++j) {
                if (height[j]>r_max_height) {
                    r_max_height=height[j];
                }
            }
            for(int j=i-1; j>=0; --j) {
                if (height[j]>l_max_height) {
                    l_max_height=height[j];
                }
            }
            int h=std::min(r_max_height, l_max_height)-height[i];
            if (h>0) {
                res+=h;
            }
        }
        return res;
    }


    // 双指针优化
    int trap2(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n=height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        left_max[0]=height[0];
        for(int i=1; i<n; ++i) {
            left_max[i]=std::max(height[i], left_max[i-1]);
        }
        right_max[n-1]=height[n-1];
        for(int i=n-2; i>=0; --i) {
            right_max[i]=std::max(height[i], right_max[i+1]);
        }

        int sum=0;
        for(int i=1; i<n-1; i++) {
            sum += std::min(left_max[i], right_max[i])-height[i];
        }
        return sum;
    }
};

int main(){

    Solution soluton;

    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout<<soluton.trap(height);
}