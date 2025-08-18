#include "../../utils/utils.h"



class Solution {
public:
    int inventoryManagement(std::vector<int>& stock) {
        std::sort(stock.begin(), stock.end());
        return stock[stock.size()/2];
    }

    int inventoryManagement1(std::vector<int>& stock) {
        std::unordered_map<int,int> cnt;
        for (const int& e: stock) {
            ++cnt[e];
            if (cnt[e]>stock.size()/2)
                return e;
        }
        return -1;
    }

    int inventoryManagement2(std::vector<int>& stock) {
        int m = stock[0];
        int cnt = 1;
        for (int i=1; i<stock.size(); ++i)
        {
            if (cnt==0) {
                m = stock[i];
                cnt = 1;
            } else if (stock[i]==m) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return m;
    }
};