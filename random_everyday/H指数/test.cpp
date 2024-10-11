#include <unordered_map>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        std::sort(citations.begin(), citations.end());

        for(int h=n; h>0; h--)
        {
            if(citations[n-h]>=h)
                return h;
        }
        return 0;
    }
    int hIndex2(vector<int>& citations) {
        int n = citations.size();
        std::unordered_map<int, int> cnts(n+1);
        for(int i=0; i<n; ++i)
        {
            if(citations[i]>=n)
            {
                cnts[n]++;
            }else{
                cnts[citations[i]]++;
            }
        }
        
        int total = 0;
        for(int h=n; h>=0; h--)
        {
            total+=cnts[h];
            if(total>=h){
                return h;
            }         
        }
        return 0;
    }
};