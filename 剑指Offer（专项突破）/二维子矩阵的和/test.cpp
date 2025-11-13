#include "../../utils/utils.h"

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        _prefixSum.resize(m+1, std::vector<int>(n+1, 0));

        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                _prefixSum[i][j] = _prefixSum[i][j-1] + _prefixSum[i-1][j] - _prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return _prefixSum[row2+1][col2+1] - _prefixSum[row1][col2+1] - _prefixSum[row2+1][col1] + _prefixSum[row1][col1]; 
    }
private:
    std::vector<std::vector<int>> _prefixSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */