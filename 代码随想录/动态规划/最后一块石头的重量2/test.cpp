#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        std::sort(stones.begin(), stones.end());
        vector<int> new_stones;
        int n=stones.size();
        for(int i=0; i<n/2; ++i) {
            int remain = stones[n-i-1]-stones[i];
            if (remain!=0) {
                new_stones.push_back(remain);
            }
        }
        // 判断大小的奇偶性
        if (n%2==1) {
            new_stones.push_back(stones[n/2]);
        }
        if (new_stones.size()==0) {
            return 0;
        } else if (new_stones.size()==1) {
            return new_stones[0];
        } else {
            return lastStoneWeightII(new_stones);
        }
    }

    int lastStoneWeightII1(vector<int>& stones) {
        // 求元素之和
        int sum=0;
        for(const int& weight: stones) {
            sum+=weight;
        }
        int target = sum/2;
        // dp数组
        vector<int> dp(target+1, 0);
        for(const int& weight: stones) {
            for(int i=target; i>=weight; --i) {
                dp[i] = std::max(dp[i], dp[i-weight]+weight);
            }
        }
        return sum-2*dp[target];

    }
};