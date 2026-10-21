
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        std::string tmp = s;
        std::reverse(tmp.begin(), tmp.end());
        std::string t = s + "#" + tmp;
        std::vector<int> nxt(t.size(), 0);
        for (int i=1; i<t.size(); ++i) {
            int j = nxt[i-1];
            while (j>0 && t[i]!=t[j]) {
                j = nxt[j-1];   
            }
            if (t[i]==t[j]) ++j;
            nxt[i] = j;
        }
        int len = nxt[t.size()-1];
        return tmp.substr(0, s.size()-len)+s;
    }
};

int main() {
    
    return 0;
}