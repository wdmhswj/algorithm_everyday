

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        const int n = s.size();
        std::vector<int> z(n, 0);
        z[0] = n;

        int l=0, r=0;
        for (int i=1; i<n; ++i) {
            if (i<=r) {
                z[i] = std::min(z[i-l], r-i+1);
            }
            while (i+z[i]<n && s[z[i]]==s[i+z[i]]) {
                ++z[i];
            }
            if (i+z[i]-1>r) {
                l = i;
                r = i+z[i]-1;
            }
        }
        long long res = 0;
        for (int x: z) res += x;
        return res;
    }
};

int main() {
    
    return 0;
}