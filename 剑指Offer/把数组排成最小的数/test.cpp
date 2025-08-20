#include "../../utils/utils.h"

class Solution {
public:
    std::string crackPassword(std::vector<int>& password) {
        std::vector<std::string> strs;
        for (const int& e: password) {
            strs.push_back(std::to_string(e));
        }
        std::sort(strs.begin(), strs.end(), [](const auto& a, const auto& b){
            return a + b < b + a;
        });
        std::string rt;
        for (const std::string& e: strs) {
            rt += e;
        }
        return rt;
    }
};