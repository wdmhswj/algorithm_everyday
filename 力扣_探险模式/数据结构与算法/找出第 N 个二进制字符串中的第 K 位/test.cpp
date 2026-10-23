#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        
        // 011 -> 100 -> 001
        // 011 -> 110 -> 001
        // 1001
        std::string S = "0";
        for (int i=2; i<=n; ++i) {
            // '1'-c+'0'
            std::string tmp = S;
            for (char& c: tmp) {
                c = '1'-c+'0';
            }
            std::reverse(tmp.begin(), tmp.end());
            S = S + "1" + tmp;
        }
        return S[k-1];
    }

    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        if (k == 1 << (n - 1)) {
            return '1';
        }
        if (k < 1 << (n - 1)) {
            return findKthBit(n - 1, k);
        }
        return findKthBit(n - 1, (1 << n) - k) ^ 1;
    }

};

int main() {
    
    return 0;
}