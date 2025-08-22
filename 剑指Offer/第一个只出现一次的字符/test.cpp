#include "../../utils/utils.h"

class Solution {
public:
    char dismantlingAction(std::string arr) {
        int count[26] = {0};
        for (const char& c: arr) {
            ++count[c-'a'];
        }
        for (const int& c: arr) {
            if (count[c-'a']==1) return c;
        }
        return ' ';
    }
};