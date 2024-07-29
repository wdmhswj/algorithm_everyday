#include <vector>
#include <stack>
// #include <unordered_map>

using std::vector;
using std::stack;
// using std::unordered_map;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        // 结果
        vector<int> res(n, -1);

        // 存储元素index的单调栈
        stack<int> st;
        st.push(0);
        for(int i=1; i<2*n; ++i) {
            while (!st.empty() && nums[i%n]>nums[st.top()]) {
               if (res[st.top()%n]==-1) {   // 还未赋值
                    res[st.top()%n] = nums[i%n];
               }
               st.pop();    // 弹出栈顶元素
            }
            st.push(i%n);   // 当前元素入栈
        }
        return res;
        
    }
};