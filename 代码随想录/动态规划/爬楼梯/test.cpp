

class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1) {
            return 1;
        }
        int dp1=1, dp2=1;
        int res=0;
        for(int i=2; i<=n; ++i) {
            res = dp1+dp2;
            dp1=dp2;
            dp2=res;
        }
        return res;
    }
};