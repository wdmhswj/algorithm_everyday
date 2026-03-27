#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string cur;
        backtrack(res, cur, 0, 0, n);
        return res;
    }

private:
    void backtrack(std::vector<std::string>& res, std::string& cur, int left, int right, int n) {
        if (left==n && right==n) {
            res.emplace_back(cur);
            return;
        }

        if (left < n) {
            cur.push_back('(');
            backtrack(res, cur, left+1, right, n);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            backtrack(res, cur, left, right+1, n);
            cur.pop_back();
        }
    }
};