#include "../../utils/utils.h"


class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        const int n = arr.size();

        std::unordered_map<int, int> map; // 记录每个元素对应的 index
        for (int i=0; i<n; ++i) {
            map[arr[i]] = i;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                dp[j][i] = 2;
            }
        }

        int res = 2;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                int prev = arr[i]-arr[j];
                if (map.count(prev)) {
                    int k = map[prev];
                    if (k<j) {
                        dp[j][i] = dp[k][j]+1;
                        res = std::max(res, dp[j][i]);
                    }
                }
            }
        }

        return res>2 ? res : 0;
    }
};