#include<vector>
#include<stack>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for(int i=1; i<temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i]>temperatures[st.top()]) {
                res[st.top()]=i-st.top();
                st.pop();   // 弹出
            }
            st.push(i); // 当前元素入栈
        }
        return res;
    }
};