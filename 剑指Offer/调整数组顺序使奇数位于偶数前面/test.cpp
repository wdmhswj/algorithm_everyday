#include "../../utils/utils.h"


class Solution {
public:
    std::vector<int> trainingPlan(std::vector<int>& actions) {
        int i=0, j=0;
        for (; i<actions.size(); ++i) {
            if (actions[i] & 1) {
                std::swap(actions[i], actions[j++]);
            }
        }
        return actions;
    }
};