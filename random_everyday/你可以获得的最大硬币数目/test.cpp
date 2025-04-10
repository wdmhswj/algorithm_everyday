#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        if(piles.size()%3 != 0) return -1;
        std::sort(piles.begin(), piles.end());
        int result = 0;
        while (!piles.empty())
        {
            piles.pop_back();
            result += piles.back();
            piles.pop_back();
            piles.erase(piles.begin());
        }
        return result;
        
    }
    int maxCoins_1(vector<int>& piles) {
        const int size = piles.size();
        if(size%3 != 0) return -1;
        std::sort(piles.begin(), piles.end());
        int result = 0;
        for(int i=size/3; i<size; i+=2)
            result += piles[i];
        return result;
        
    }
};