
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        int cnt[26] = {0};

        for (int right = 0; right < n; ++right) {
            // 1. 把 s[right] 加入窗口
            cnt[s[right]-'A']++;
            // 2. 更新 maxFreq
            for (int i=0; i<26; ++i) {
                maxFreq = std::max(maxFreq, cnt[i]);
            }
            // 3. 如果窗口不合法，移动 left
            while (right-left+1-maxFreq > k) {
                cnt[s[left]-'A']--;
                ++left;
            }
            // 4. 更新 ans
            ans = std::max(ans, right-left+1);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        const int n = s.size();
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        int cnt[26] = {0};

        for (int right = 0; right < n; ++right) {
            // 1. 把 s[right] 加入窗口
            cnt[s[right]-'A']++;
            // 2. 更新 maxFreq   
            maxFreq = std::max(maxFreq, cnt[s[right]-'A']);
            // 3. 如果窗口不合法，移动 left
            if (right-left+1-maxFreq > k) {
                cnt[s[left]-'A']--;
                ++left;
            }
            // 4. 更新 ans
            ans = std::max(ans, right-left+1);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}