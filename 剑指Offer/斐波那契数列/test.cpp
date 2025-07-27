

class Solution {
public:
    int fib(int n) {
        // 1000000007
        int a=0, b=1, c=-1;
        while (n--) {
            c = (a + b)% 1000000007; // f(n+1)=f(n-1)+f(n)
            a = b; // f(n)
            b = c; // f(n+1)
        }
        return a ;
    }
};