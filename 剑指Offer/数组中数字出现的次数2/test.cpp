#include "../../utils/utils.h"

class Solution {
public:
    int trainingPlan(std::vector<int>& actions) {
        int count[32] = {0};
        for (const int& e: actions) {
            for (int i=0; i<32; ++i) {
                if(e & (1<<i)) {
                    ++count[i];
                }
            }
        }

        int rt = 0;
        for (int i=0; i<32; ++i) {
            if (count[i]%3!=0) {
                rt |= (1<<i);
            }
        }
        return rt;
    }

    int trainingPlan1(std::vector<int>& actions) {
        int count[32] = {0};
        for (int e: actions) {
            for (int i=0; i<32; ++i) {
                count[i] += e & 1;
                e >>= 1;
            }
        }

        int rt = 0;
        for (int i=0; i<32; ++i) {
            if (count[i]%3!=0) {
                rt |= (1<<i);
            }
        }
        return rt;
    }
};