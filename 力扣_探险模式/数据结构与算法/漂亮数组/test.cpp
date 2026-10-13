
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n==1) return {1};
        std::vector<int> left = beautifulArray((n+1)/2);
        std::vector<int> right = beautifulArray(n/2);
        std::vector<int> res;
        res.reserve(left.size() + right.size());
        for (int x: left) {
            res.push_back(2 * x - 1);
        }
        for (int x: right) {
            res.push_back(2 * x);
        }
        return res;
    }
};

int main() {
    
    return 0;
}