#include "../../utils/utils.h"

class Solution {
public:
    int dismantlingAction(std::string arr) {
        const int n = arr.size();
        if (n==0) return 0;
        int i=0, j=0;
        int rt = 0;
        std::unordered_set<char> visited;
        for ( ; i<n; ++i) {
            while (visited.count(arr[i])) {
                visited.erase(arr[j]);
                ++j;
            }
            visited.insert(arr[i]);
            rt = std::max(rt, i-j+1);
        }
        return rt;
    }
};