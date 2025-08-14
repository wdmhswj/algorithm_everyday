#include "../../utils/utils.h"

class Solution {
public:
    bool validateBookSequences(std::vector<int>& putIn, std::vector<int>& takeOut) {
        std::stack<int> stk;
        int i = 0;
        for (int j=0; j<putIn.size(); ++j) {
            stk.push(putIn[j]);
            while (!stk.empty() && stk.top()==takeOut[i]) {
                stk.pop();
                ++i;
            }
        }
        return i==takeOut.size();
    }
};