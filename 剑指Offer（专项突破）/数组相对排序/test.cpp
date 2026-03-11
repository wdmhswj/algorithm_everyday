#include "../../utils/utils.h"


class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> map;
        for (int i=0; i<arr2.size(); ++i) {
            map[arr2[i]] = i;
        }

        std::sort(arr1.begin(), arr1.end(), [&map](int l, int r) {
            auto it_l = map.find(l);
            auto it_r = map.find(r);
            
            // 如果都在 arr2 中，按索引排序
            if (it_l != map.end() && it_r != map.end()) {
                return it_l->second < it_r->second;
            }
            // 如果只有一个在 arr2 中，在其中的那个更小
            if (it_l != map.end()) return true;
            if (it_r != map.end()) return false;
            
            // 都不在 arr2 中，按数值升序
            return l < r;
        });

        return arr1;
    }

    std::vector<int> relativeSortArray1(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> map;
        int n = arr2.size();
        for (int i=0; i<n; ++i) {
            map[arr2[i]] = i;
        }

        auto get_weight = [&](int x) {
            auto it = map.find(x);
            return it==map.end() ? n+x : it->second;
        };

        std::vector<std::pair<int, int>> temp;
        for (int x: arr1) temp.push_back({get_weight(x), x});
        std::sort(temp.begin(), temp.end());
        for (int i=0; i<arr1.size(); ++i) arr1[i] = temp[i].second;
        return arr1;
    }

    std::vector<int> relativeSortArray1(std::vector<int>& arr1, std::vector<int>& arr2) {
        auto [min, max] = std::minmax_element(arr1.begin(), arr1.end());
        std::vector<int> cnt(*max + 1);
        for (int x: arr1) cnt[x]++;
        
        std::vector<int> ret;
        ret.reserve(arr1.size());

        for (int x: arr2) {
            while (cnt[x]>0) {
                ret.push_back(x);
                --cnt[x];
            }
        }

        for (int i=*min; i<=*max; ++i) {
            while (cnt[i]>0) {
                ret.push_back(i);
                --cnt[i];
            }
        }

        return ret;
    }
};