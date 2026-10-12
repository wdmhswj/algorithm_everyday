
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = static_cast<int>(std::sqrt(c));
        while (a<=b) {
            int a2 = a*a, b2 = b*b;
            if (a2 == c - b2) return true;
            else if (a2 < c - b2) ++a;
            else --b;
        }
        return false;
    }
};

int main() {
    
    return 0;
}