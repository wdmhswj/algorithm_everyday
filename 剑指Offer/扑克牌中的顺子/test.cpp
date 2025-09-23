#include "../../utils/utils.h"


class Solution {
public:
    bool checkDynasty(std::vector<int>& places) {
        int max = -1;
        int min = 14;
        std::unordered_set<int> s;
        for (const int& e: places)
        {
            if (e==0) continue;
            if (auto it = s.find(e); it!=s.end())
            {
                return false;
            }
            s.insert(e);
            max = std::max(max, e);
            min = std::min(min, e);

            std::cout << "max="<<max << " min=" << min << std::endl;
        }
        return max-min>4 ? false : true;
    }
};


int main()
{
    std::vector<int> input = {0,6,9,0,7};
    Solution s;
    std::cout << s.checkDynasty(input);
}