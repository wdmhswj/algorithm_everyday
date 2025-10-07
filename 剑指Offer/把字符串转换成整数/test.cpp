#include "../../utils/utils.h"

class Solution {
public:
    int myAtoi(std::string str) {
        int i = 0;
        const int n = str.size();
        // 跳过开头空格
        while (i<n && str[i]==' ')
        {
            ++i;
        }
        if (i>=n)
        {
            return 0;
        }

        // 检查是否是正常整数字符
        int sign = 1;   // 符号

        if (str[i]=='-')
        {
            sign = -1;
            ++i;
        } else if (str[i]=='+')
            ++i;
        else if (str[i]<'0' || str[i]>'9')
            return 0;

        // 转换，2^31 = 2147483648
        int rt = 0;
        int boundary = INT_MAX/10;
        while (i<n && str[i]>='0' && str[i]<='9')
        {
            std::cout << "rt=" << rt << " str[" << i << "]=" << str[i] << std::endl;
            int digit = str[i]-'0';
            if (rt>boundary || (rt==boundary && digit>7))
                return sign==1 ? INT_MAX : INT_MIN;

            rt = rt*10 + digit;
            ++i;
        }
        return sign*rt;
    }
};


int main() {

    Solution s;
    std::cout << s.myAtoi("2147483646");

    return 0;
}