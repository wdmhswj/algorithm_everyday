
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.size();
        // int win_size = 3;
        int res = 0;
        for (int win_size=3; win_size<=n; ++win_size) {
            std::vector<int> cnt(3, 0);
            for (int i=0; i<n; ++i) {
                if (i>=win_size) {
                    // 判断是否满足条件
                    if (cnt[0]>0 && cnt[1]>0 && cnt[2]>0) ++res;
                    cnt[s[i-win_size]-'a']--;
                }
                cnt[s[i]-'a']++;
            }
            if (cnt[0]>0 && cnt[1]>0 && cnt[2]>0) ++res;
        }
        return res;
    }

    int numberOfSubstrings(string s) {
        const int n = s.size();
        int res = 0;
        int left = 0;
        int cnt[3] = {0, 0, 0};
        for (int right=0; right<n; ++right) {
            cnt[s[right]-'a']++;
            while (cnt[0]>0 && cnt[1]>0 && cnt[2]>0) {
                --cnt[s[left]-'a'];
                ++left;
            }
            res += left;
        }
        return res;
    }
};

int main() {
    
    return 0;
}