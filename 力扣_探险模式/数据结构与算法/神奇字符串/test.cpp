#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        int ptr = 0; // 最新末尾指针
        int p_cnt = 1; // 计数器指针
        
        int res = 0;
        std::string magic_str = "1";
        magic_str.reserve(n + 2);
        while (ptr < n) {
            char tail = magic_str[ptr];
            char next = '1' + '2'-tail;
            magic_str.push_back(next);
            ++ptr;
            if (magic_str[p_cnt]=='2') {
                magic_str.push_back(next);
                ++ptr;
            }
            ++p_cnt;
        }
        for (int i=0; i<n; ++i) {
            res += magic_str[i]=='1';
        }
        return res;
    }
};

int main() {
    // 1
    // 12
    return 0;
}