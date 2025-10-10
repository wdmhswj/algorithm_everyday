#include "../../utils/utils.h"

class Solution {
public:
    int divide(int a, int b) {
        // 特殊情况
        if (b==1) return a;
        if (a==INT_MIN && b==-1) return INT_MAX;

        // 判断商的正负
        bool sign = (a>0 && b>0) || (a<0 && b<0);

        // 将除数和被除数都转换为负数处理
        a = a>0 ? -a : a;
        b = b>0 ? -b : b;

        int rt = 0;
        while (a<=b)    // 被除数的绝对值大于等于除数
        {
            int x = b;  // 内部循环确定的被除数减去的数
            int cnt = 1;    // x对于b的倍数
            while ((x>=(INT_MIN>>1) && (a<=(x<<1))))    // 确保除数x不溢出，同时x绝对值小于被除数a
            {   
                x <<= 1;
                cnt <<= 1;
            }
            rt += cnt;
            a -= x;
        }
        return sign ? rt : -rt;
    }
};