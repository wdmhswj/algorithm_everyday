#include <vector>

using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        vector<int> candy(ratings.size(), 1);
        for (int i=1; i<ratings.size(); ++i) {
            if (ratings[i]>ratings[i-1]) {
                candy[i]=candy[i-1]+1;
            }
        }
        for (int i=ratings.size()-2; i>=0; --i) {
            if (ratings[i]>ratings[i+1] && (candy[i+1]+1>candy[i])) {   // ratings 为山峰状的情况
                candy[i]=candy[i+1]+1;
            }
        }
        int sum = 0;
        for (int& c : candy) {
            sum+=c;
        }
        return sum;
    }
};