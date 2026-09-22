#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int height = 0;
        for (int g: gain) {
            height += g;
            res = std::max(res, height);
        }
        return res;
    }
};

int main() {
    
    return 0;
}