#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        const int n1 = a.size();
        const int n2 = b.size();
        int min = (n2 + n1 - 1)/n1;
        int max = min + 1;

        std::string aa;
        for (int i=0; i<max; ++i)
            aa += a;
        
        std::vector<int> next = buildNext(b);
        int n = aa.size();
        for (int i=0, j=0; i<n; ++i) {
            while (j>0 && aa[i]!=b[j]) {
                j = next[j-1];
            }
            if (aa[i]==b[j]) ++j;

            if (j==n2) {
                if (i<n1*min) return min;
                return max;
            }
        }
        return -1;
    }

private:
    std::vector<int> buildNext(const std::string& pattern) {
        int m = pattern.size();
        std::vector<int> next(m, 0);
        for (int i=1, j=0; i<m; ++i) {
            while (j>0 && pattern[i]!=pattern[j]) {
                j = next[j-1];
            }
            if (pattern[i]==pattern[j]) ++j;
            
            next[i] = j; 
        }
        return next;
    }
};

int main() {
    
    return 0;
}