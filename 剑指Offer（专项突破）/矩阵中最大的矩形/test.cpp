#include "../../utils/utils.h"

class Solution {
public:
    int maximalRectangle(std::vector<std::string>& matrix) {
        const int n = matrix.size();
        if (n==0) return 0;
        const int m = matrix[0].size();
        std::array<int, 201> h = {};
        std::array<int, 201> l = {};
        l.fill(-1);
        std::stack<int> st;
        int ret = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                h[j] = matrix[i][j]=='1' ? h[j]+1 : 0;
                while (!st.empty() && h[j]<=h[st.top()]) {
                    ret = std::max(ret, (j-l[st.top()]-1)*h[st.top()]);
                    st.pop();
                }
                l[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }
            while (!st.empty()) {
                ret = std::max(ret, (m-l[st.top()]-1)*h[st.top()]);
                st.pop();
            }
        }
        return ret;

    }
};