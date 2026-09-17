#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        const int n = s.size();
        
        int res = 0, cnt = 0;
        for (int i=0; i<k; ++i) {
            cnt += _isYuanYin(s[i]);
        }
        res = std::max(res, cnt);
        int l=1, r=k;
        for (; r<n; ++r, ++l) {
            if (_isYuanYin(s[l-1])) --cnt;
            if (_isYuanYin(s[r])) ++cnt;
            res = std::max(res, cnt);
            if (res==k) break;
        }
        return res;

    }
private:
    bool _isYuanYin(char c) {
        switch (c) {
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u': return true;
        }
        return false;
    }
};

int main() {
    
    return 0;
}