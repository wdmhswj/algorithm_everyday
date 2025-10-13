#include "../../utils/utils.h"

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int i=a.size()-1, j=b.size()-1;
        std::string rt;
        for (int carry=0; i>=0 || j>=0 || carry>0; --i, --j)
        {
            // 计算进位
            carry += (i>=0 ? a[i]-'0' : 0) + (j>0 ? b[j]-'0' : 0);
            // 当前位
            rt.push_back(carry%2+'0');

            carry/=2;
        }
        std::reverse(rt.begin(), rt.end());
        return rt;
    }
};