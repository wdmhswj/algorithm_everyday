#include "../../utils/utils.h"

class Solution {
public:
    int findKthNumber(int k) {
        int cap = 1;
        int cnt = 9;
        while (k - 1ll * cap * cnt > 0) {
            k -= cap * cnt;
            ++cap;
            cnt*=10;
        }
        int num = std::pow(10, cap-1) + (k-1)/cap;
        return std::to_string(num)[(k-1)%cap]-'0';
    }
};