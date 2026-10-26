
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        auto p = _decode(s, 0);
        return p.first;
    }

private:
    std::pair<std::string, int> _decode(const std::string& s, int pos) {
        std::string res;
        int cnt = 0;
        while (pos<s.size() && s[pos]!=']') {
            if (s[pos]>='a' && s[pos]<='z') {
                res += s[pos];
                ++pos;
            } else if (s[pos]>='0' && s[pos]<='9') {
                cnt = cnt*10 + s[pos]-'0';
                ++pos;
            } else {
                auto p = _decode(s, pos+1);
                for (int j=0; j<cnt; ++j)
                    res += p.first;
                cnt = 0;
                pos = p.second+1;
            }
        }
        return {res, pos};
    }
};

int main() {
    
    return 0;
}