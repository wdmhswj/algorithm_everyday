#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        const int n = goal.size();
        for (int i=0; i<n; ++i) {
            bool match = true;
            for (int j=0; j<n; ++j) {
                if (s[(i+j)%n] != goal[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=std::string::npos;
    }
};

int main() {
    
    return 0;
}