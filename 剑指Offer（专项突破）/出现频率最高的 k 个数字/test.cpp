#include "../../utils/utils.h"


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cnt;
        for (const int& e: nums)
        {
            ++cnt[e];
        }
        using pii = std::pair<int, int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        for (const auto& e: cnt)
        {
            pq.push({e.second, e.first});
            if (pq.size()>k) pq.pop();
        }

        std::vector<int> ret(k);
        for (std::size_t i=0; i<k; ++i)
        {
            ret[i] = pq.top().second;
            pq.pop();
        }
        return ret;
    }
};