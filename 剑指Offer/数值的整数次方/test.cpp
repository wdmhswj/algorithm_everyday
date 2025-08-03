#include "../../utils/utils.h"
class Solution {
public:
    double myPow(double x, int n) {
        auto mpow = [](double x, long long n) {
            double ans = 1;
            for (; n; n >>= 1) {
                if (n&1) ans *= x;
                x *= x;
            }
            return ans;
        };
        return n >=0 ? mpow(x, n) : mpow(1/x, - static_cast<long long>(n));
    }
};