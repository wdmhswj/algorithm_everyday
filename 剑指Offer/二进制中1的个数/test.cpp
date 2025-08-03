#include "../../utils/utils.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            int mod = n % 2;
            if (mod==1) ++count;
            mod /= 2;
        }
        return count;
    }

    int hammingWeight1(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n-1);
            ++count;
        }
        return count;
    }

    int hammingWeight2(uint32_t n) {
        int count = 0;
        while (n) {
            n -= n&(-n);
            ++count;
        }
        return count;
    }
};