#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k <= 0) return {};

        auto cmp = [](const std::tuple<int,int,int>& a, const std::tuple<int,int,int>& b) {
            return std::get<0>(a) > std::get<0>(b);
        };
        std::priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>, decltype(cmp)> pq;

        std::vector<std::vector<int>> res;
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        for (int i=0; i<n1 && i<k; ++i) {
            pq.push({nums1[i]+nums2[0], i, 0});
        }

        while (!pq.empty() && res.size()<k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j+1<n2) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }
        

        return res;
    }
};