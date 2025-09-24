#include "../../utils/utils.h"


class Solution {
public:
    int iceBreakingGame(int num, int target) {
        return f(num, target);
    }

    int f(int n, int m) {
        if (n<1) return -1;
        if (n==1) return 0;
        return (f(n-1, m) + m)%n;
    }

    int iceBreakingGame1(int num, int target) {
        int f = 0;
        for (int n=2; n<=num; ++n) {
            f = (f+target)%n;
        }
        return f;
    }
};