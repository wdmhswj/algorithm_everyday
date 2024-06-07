#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
private:
    void backtracking(const int& n, int row, vector<vector<string>>& res, vector<string>& path) {
        if (row >= n) {
            res.push_back(path);
            return;
        }
        for(int i=0; i<n; ++i) {
            if (isValid(row, i, path, n)) {
                path[row][i] = 'Q';
                backtracking(n, row+1, res, path);
                path[row][i] = '.';
            }
            
        }
    }
    bool isValid(int row, int col, const vector<string>& path, const int& n) {
        // 列
        for(int i=0; i<row; ++i) {
            if (path[i][col] == 'Q') {
                return false;
            }
        }
        // 135度
        for(int i=row-1, j=col-1; i>=0&&j>=0; --i,--j) {
            if (path[i][j] == 'Q') {
                return false;
            }
        }
        // 45度
        for(int i=row-1, j=col+1; i>=0&&j<n; --i,++j) {
            if (path[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n<=0) {
            return {};
        }
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        backtracking(n, 0, res, path);
        return res;
    }
};