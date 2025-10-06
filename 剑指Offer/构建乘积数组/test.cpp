#include "../../utils/utils.h"


class Solution {
public:
    std::vector<int> statisticalResult(std::vector<int>& arrayA) {
        int tmp = 1;
        std::vector<int> rt(arrayA.size(), 1);
        for (int i=0; i<arrayA.size(); ++i)
        {
            rt[i] = tmp;
            tmp *= arrayA[i];
        }

        tmp = 1;
        for (int j=arrayA.size()-1; j>=0; --j)
        {
            rt[j] *= tmp;
            tmp *= arrayA[j];
        }
        
        return rt;
    }
};