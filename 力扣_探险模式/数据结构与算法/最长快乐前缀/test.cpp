
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        const int n = s.size();
        if (n<=1) return "";
        std::vector<int> nxt(n, 0);
        for (int i=1; i<n; ++i) {
            int j = nxt[i-1];
            while (j>0 && s[i]!=s[j]) {
                j = nxt[j-1];
            }
            if (s[i]==s[j]) ++j;
            nxt[i] = j;
        }
        int len = nxt[n-1];
        return s.substr(0, len);
    }
};

int main() {
    
    return 0;
}