#include "../../utils/utils.h"


class Solution {
public:
    std::string dynamicPassword(std::string password, int target) {
        return password.substr(target) + password.substr(0, target);
    }

    std::string dynamicPassword1(std::string password, int target) {
        std::reverse(password.begin(), password.begin()+target);
        std::reverse(password.begin()+target, password.end());
        std::reverse(password.begin(), password.end());
        return password;
    }
};