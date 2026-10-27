
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> res;
        std::string path;
        _backtrack(res, s, path, 0, 0);
        return res;
    }

private:
    void _backtrack(std::vector<std::string>& res, const std::string& s, std::string& path, int segment, int pos) {
        if (segment == 4) {
            if (pos==s.size()) {
                res.push_back(path.substr(0, path.size()-1));
            }
            return;
        }

        // 剪枝
        if ((s.size()-pos) < (4-segment) || (s.size()-pos) > 3*(4-segment))
            return;
        
        for (int i=1; i<=3; ++i) {
            if (pos+i > s.size()) break; // 长度超过范围
            if (i>1 && s[pos]=='0') break; // 不能包含前导0
            if (i==3) {
                int num = 0;
                num = num*10 + s[pos]-'0';
                num = num*10 + s[pos+1]-'0';
                num = num*10 + s[pos+2]-'0';
                if (num>255) break;
            }
            path += s.substr(pos, i);
            path += ".";
            _backtrack(res, s, path, segment+1, pos+i);
            path.erase(path.size()-(i+1));
        }
    }
};

int main() {
    
    return 0;
}