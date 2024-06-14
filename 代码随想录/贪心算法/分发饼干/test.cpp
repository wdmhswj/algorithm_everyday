#include <algorithm>
#include<vector>

using std::vector;

class Solution {
public:
    // g胃口，s饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int index_c=0;
        // int result = 0;
        for (int index_b=0; index_b<s.size(); ++index_b) {
            if (index_c<g.size() && g[index_c]<=s[index_b]) {
                // result++;
                index_c++;
            }
        }
        return index_c;
    }
};