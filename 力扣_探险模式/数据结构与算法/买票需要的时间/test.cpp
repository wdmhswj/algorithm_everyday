#include "../../../utils/utils.h"

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        // [1, 2, 3], k=1
        // [0, 1, 2], t=3 -> [0, 0, 2], t=4
        // 2 + 1 + 1 = 4
        // [2,3,2], k = 2
        // t[k]-1 all: if t[i]<= t[k]-1: res+=t[i]; else: res+=t[k]-1
        // 1 0~k: if t[i]<=t[k]-1: res+=0; else: res+=1
        // 
        const int n = tickets.size();

        int res = tickets[k];
        for (int i=0; i<k; ++i) {
            if (tickets[i]<=tickets[k]) res += tickets[i];
            else res += tickets[k];
        }
        for (int i=k+1; i<n; ++i) {
            if (tickets[i]<=tickets[k]-1) res += tickets[i];
            else res += tickets[k]-1;
        }

        return res;

    }


    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int res = tickets[k];
        for (int i=0; i<k; ++i) {
            res += std::min(tickets[i], tickets[k]);
        }
        for (int i=k+1; i<tickets.size(); ++i) {
            res += std::min(tickets[i], tickets[k]-1);
        }

        return res;
    }
};