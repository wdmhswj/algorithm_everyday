#include <vector>
using std::vector;

class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (board[i][j]=='.') {
                    for (char k='1'; k<='9'; ++k) {
                        if (isValid(board, k, i, j)) {
                            board[i][j] = k;
                            if (backtracking(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                } 
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, const char k, int row, int col) {
        // 行
        for (int i=0; i<board[0].size(); ++i) {
            if (board[row][i]==k) {
                return false;
            }
        }
        // 列
        for (int i=0; i<board.size(); ++i) {
            if (board[i][col]==k) {
                return false;
            }
        }
        // 3x3
        int block_0 = row/3, block_1 = col/3;
        for(int i = block_0*3; i<block_0*3+3; ++i) {
            for (int j = block_1*3; j<block_1*3+3; ++j) {
                if (board[i][j]==k) {
                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        backtracking(board);
    }
};