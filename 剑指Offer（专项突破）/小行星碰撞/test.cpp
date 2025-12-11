#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> ret;
        for (const int& e: asteroids) {
            if (e>0) {
                ret.push_back(e);
            } else {
                while (ret.size()>0 && ret.back()>0 && ret.back()<-e) {
                    ret.pop_back();
                }
                if (ret.size()>0 && ret.back()==-e) {
                    ret.pop_back();
                } else if (ret.empty() || ret.back()<0) {
                    ret.push_back(e);
                }
            }
        }
        return ret;
    }
};