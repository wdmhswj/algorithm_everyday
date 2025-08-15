#include "../../utils/utils.h"

class Solution {
public:
    bool verifyTreeOrder(std::vector<int>& postorder) {
        
        std::function<bool(int, int)> dfs = [&](int l, int r) -> bool {
            if (l>=r) return true;
            int root_value = postorder[r];
            int i = -1;
            for (i=l; i<r; ++i) {
                if (postorder[i]>=root_value) break;
            }
            for (int j=i+1; j<r; ++j) {
                if (postorder[j]<root_value) return false;
            }
            return dfs(l, i-1) && dfs(i,r-1);
        };

        return dfs(0, postorder.size()-1);
    }

    bool verifyTreeOrder1(std::vector<int>& postorder) {
        
        std::stack<int> st;
        int root = INT_MAX;
        for (int i=postorder.size()-1; i>=0; --i)
        {
            if (postorder[i]>root) return false;
            while (!st.empty() && postorder[i]<st.top()) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }

        return true;


    }
};