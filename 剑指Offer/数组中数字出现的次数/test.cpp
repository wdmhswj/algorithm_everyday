#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> sockCollocation(std::vector<int>& sockets) {
        const int n = sockets.size();
        if (n<2) return {};
        int xor_res = 0;
        for (const int& e: sockets) {
            xor_res ^= e;
        }
        // 最低有效位
        int low_bit = xor_res & -xor_res;
        int l=0;
        for (const int& e: sockets) {
            if (e & low_bit) {
                l ^= e;
            }
        }
        int r = xor_res ^ l;
        return {l, r};
    }
};