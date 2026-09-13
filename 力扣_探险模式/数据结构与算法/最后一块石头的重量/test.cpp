#include "../../../utils/utils.h"

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        int x = 0, y = 0, z = 0;
        while (pq.size() >= 2) {
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();
            z = y-x;
            if (z>0) pq.push(z);
        }

        if (!pq.empty()) return pq.top();
        else return 0;
    }
};