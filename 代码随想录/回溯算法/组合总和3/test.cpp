#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (path.size()==k) {
            if (sum == targetSum) {
                res.push_back(path);
            }
            return;
        }
        for (int i=startIndex; i<=9-(k-path.size())+1; ++i) {
            sum += i;
            path.push_back(i);
            if (sum>targetSum) {
                sum -= i;
                path.pop_back();
                return;
            }
            backtracking(targetSum, k, sum, i+1);
            sum -= i;
            path.pop_back();
        }
    }

    void backtracking_1(int targetSum, int k, int sum, int startIndex) {
        if (path.size()==k) {
            if (sum == targetSum) {
                res.push_back(path);
            }
            return;
        }
        for (int i=startIndex; i<=9-(k-path.size())+1; ++i) {
            // sum += i;
            path.push_back(i);
            if (sum>targetSum) {
                // sum -= i;
                path.pop_back();
                return;
            }
            backtracking(targetSum, k, sum+i, i+1);
            // sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return res;
    }
};