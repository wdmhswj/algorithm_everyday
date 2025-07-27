class Solution {
public:
    int trainWays(int num) {
        // 1000000007
        int a=1, b=1, c=-1; // f(0), f(1)
        while (num--) {
            c = (a+b)%1000000007;    // 
            a = b;
            b = c;
        }
        return a;
    }
};