#include <vector>

using std::vector;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.empty()) {
            return true;
        }
        int num_5 = 0;
        int num_10 = 0;
        for (const int& bill : bills) {
            if (bill==5) {
                ++num_5;
            } else if (bill == 10) {
                ++num_10;
                --num_5;
                
            } else if (bill == 20) {
                if (num_10==0) {
                    num_5-=3;
                } else {
                    --num_10;
                    --num_5;
                }
            } else {
                return false;
            }
            if (num_5<0 || num_10<0) {
                return false;
            }
        }
        return true;
    }
};