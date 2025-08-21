#include "../../utils/utils.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        std::priority_queue<long, std::vector<long>, std::greater<long>> q;
        std::unordered_set<long> visited;
        q.push(1l);
        visited.insert(1l);
        std::vector<int> factor = {2, 3, 5};
        long rt = 0;
        while (n--) {
            rt = q.top();
            std::cout << "\trt = " << rt << std::endl;
            q.pop();
            for (const int& f: factor) {
                long nxt = rt*f;
                std::cout << "nxt = " << nxt << std::endl;
                if (!visited.count(nxt)) {
                    q.push(nxt);
                    std::cout << "q.push(nxt), nxt = " << nxt << std::endl;
                    visited.insert(nxt);
                }
            }
        }
        return (int)rt;
    }

    int nthUglyNumber1(int n) {
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        int p2=0, p3=0, p5=0;
        for (int i=1; i<n; ++i)
        {   
            int nxt2 = dp[p2]*2;
            int nxt3 = dp[p3]*3;
            int nxt5 = dp[p5]*5;
            dp[i] = std::min(nxt2, std::min(nxt3, nxt5));
            if (dp[i]==nxt2) ++p2;
            if (dp[i]==nxt3) ++p3;
            if (dp[i]==nxt5) ++p5;
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    std::cout << s.nthUglyNumber(10) << std::endl;
}