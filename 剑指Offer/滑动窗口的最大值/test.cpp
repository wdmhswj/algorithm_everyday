#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> maxAltitude(std::vector<int>& heights, int limit) {
        std::deque<int> q;
        std::vector<int> rt;
        const int n = heights.size();

        for (int i=0; i<n; ++i)
        {
            if (!q.empty() && i-q.front()+1>limit)
            {  
                q.pop_front();
            }

            while (!q.empty() && heights[q.back()]<heights[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            if (i>=limit-1)
            {
                rt.push_back(heights[q.front()]);
            }
        }
        return rt;
    }
};