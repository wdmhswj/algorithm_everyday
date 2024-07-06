

class Solution {
public:
    int fib(int n) {
        if (n<0) {
            return -1;
        }
        if (n==0) {
            return 0;
        }
        if (n==1) {
            return 1;
        }
        int res = 0;
        int Fn1=0, Fn2=1;
        for (int i=2; i<=n; ++i) {
            res = Fn1+Fn2;
            Fn1=Fn2;
            Fn2 = res;
        }
        return res;
    }
};