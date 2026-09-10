#include "../../../utils/utils.h"

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int cnt1 = std::accumulate(students.begin(), students.end(), 0);
        int cnt0 = students.size() - cnt1;
        for (int s: sandwiches) {
            if (s==0 && cnt0>0) --cnt0;
            else if (s==1 && cnt1>0) --cnt1;
            else break;
        }
        return cnt0+cnt1;
    }
};