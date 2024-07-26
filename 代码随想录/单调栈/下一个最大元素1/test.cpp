#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return {};
        }
        vector<int> res(nums1.size(), -1);

        unordered_map<int, int> map;
        for (int i=0; i<nums1.size(); ++i) {
            map[nums1[i]]=i;
        }

        stack<int> st;
        st.push(nums2[0]);
        
        for(int i=1; i<nums2.size(); ++i) {
            while (!st.empty() && nums2[i]>st.top()) {
                if (map.find(st.top())!=map.end()) {    // 栈顶元素是nums中的值
                    res[map[st.top()]]=nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);  // 当前元素入栈
        }

        return res;

    }
};