class Solution {
public:
    int trailingZeroes(int n) {
        if (n==0) {
            return 0;
        }
        // int count_10 = 0;
        int count_2 = 0;
        int count_5 = 0;

        for(int i=1; i<=n; i++)
        {
            count_2 += count(i, 2);
            count_5 += count(i, 5);
        }

        if (count_2<=count_5) {
            return count_2;
        }else {
            return count_5;
        }

    }

    int trailingZeroes2(int n) {
        int ans = 0, now = 5;
        while(now<=n)
        {
            ans += n/now;
            now*=5;
        }
        return ans;
    }
private:

    int count(int n, int factor) {
        int res = 0;
        while (n) {
            int tail = n%factor;
            if (tail==0) {
                ++res;
                n/=factor;
            }else {
                break;
            }
        }
        return res;
    }
};

