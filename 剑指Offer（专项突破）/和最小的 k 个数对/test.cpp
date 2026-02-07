#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        using pii = std::pair<int, int>;

        auto cmp = [](pii l, pii r) {
            return l.first+l.second < r.first+r.second; // 和较小的优先级低
        };
        std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);  // 堆顶是和最大的

        for (std::size_t i = 0; i < nums1.size() && i < k; ++i) {
            for (std::size_t j = 0; j < nums2.size() && j < k; ++j) {
                pq.push({nums1[i], nums2[j]});
                if (pq.size() > k) pq.pop();
            }
        }

        std::vector<std::vector<int>> ret;
        while (!pq.empty()) {
            pii e = pq.top(); pq.pop();
            ret.push_back({e.first, e.second});
        }
        return ret;
    }

    std::vector<std::vector<int>> kSmallestPairs1(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k<=0) return {};

        using Tuple = std::tuple<int, int, int>; // <sum, i, j>

        std::priority_queue<Tuple, std::vector<Tuple>, std::greater<Tuple>> pq;

        for (std::size_t i=0; i<nums1.size() && i<k; ++i) {
            pq.push({nums1[i]+nums2[0], i, 0});
        }

        std::vector<std::vector<int>> ret;
        while (k-->0 && !pq.empty()) {
            auto [sum, i, j] = pq.top(); pq.pop();
            ret.push_back({nums1[i], nums2[j]});
            if (j+1<nums2.size()) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }
        return ret;
    }


};