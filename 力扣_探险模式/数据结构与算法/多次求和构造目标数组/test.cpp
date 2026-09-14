#include "../../../utils/utils.h"

class Solution {
public:
    bool isPossible(std::vector<int>& target) {
        const int n = target.size();
        if (n==0) return false;
        if (n==1) return target[0]==1;

        long long sum = std::accumulate(target.begin(), target.end(), 0LL);
        long long rest = 0;
        std::priority_queue<long long> pq(target.begin(), target.end());

        while (!pq.empty()) {
            long long max = pq.top(); pq.pop();
            rest = sum - max;
            if (max==1) return true;
            if (max <= rest) {
                return false;
            }
            
            long long new_val = max % rest;
            if (new_val==0) new_val = rest;
            sum = sum - max + new_val;
            pq.push(new_val);
        }
        return false;
    }
};