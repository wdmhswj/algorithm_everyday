#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int res = 0;
        int low = prices[0];
        int high = prices[0];
        for (int i=0; i<prices.size(); ++i) {
            if (prices[i]>=high) {
                high = prices[i];
            } else {
                res += (high-low);
                low = prices[i];
                high = prices[i];
            }
        }
        res += (high-low);
        return res;
    }

    int maxProfit1(vector<int>& prices) {
        if (prices.size()<=1) {
            return 0;
        }
        int res = 0;
        for(int i=1; i<prices.size(); ++i) {
            if (prices[i]>prices[i-1]) {
                res += (prices[i]-prices[i-1]);
            }
        }
        return res;
    }
};