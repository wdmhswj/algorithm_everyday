#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> spiralArray(std::vector<std::vector<int>>& array) {
        
        const int m = array.size();
        if (m==0) return {};
        const int n = array[0].size();
        if (n==0) return {};

        std::vector<int> ans;
        // 可在构造 ans 前执行 ans.reserve(m * n) 以避免多次扩容
        ans.reserve(m*n);


        std::function<void(std::vector<std::vector<int>>&, std::vector<int>&, int, int)> dfs = [&](std::vector<std::vector<int>>& array, std::vector<int>& ans, int mm, int nn) {
            if (mm<=0 || nn<=0) return;

            
            int begin_row = (m-mm)/2;
            int begin_col = (n-nn)/2;
            int end_row = begin_row+mm-1;
            int end_col = begin_col+nn-1;

            // 剩余只有一行
            if (mm == 1) {
                for (int i = begin_col; i <= end_col; ++i) {
                    ans.push_back(array[begin_row][i]);
                }
                return;
            }
            // 剩余只有一列
            if (nn == 1) {
                for (int i = begin_row; i <= end_row; ++i) {
                    ans.push_back(array[i][begin_col]);
                }
                return;
            }

            for (int i=begin_col; i<end_col; ++i) {
                ans.push_back(array[begin_row][i]);
            }
            for (int i=begin_row; i<end_row; ++i) {
                ans.push_back(array[i][end_col]);
            }
            for (int i=end_col; i>begin_col; --i) {
                ans.push_back(array[end_row][i]);
            }
            for (int i=end_row; i>begin_row; --i) {
                ans.push_back(array[i][begin_col]);
            }
            dfs(array, ans, mm-2, nn-2);
        };
        dfs(array, ans, m, n);
        return ans;
    }

    std::vector<int> spiralArray(std::vector<std::vector<int>>& array) {
        const int m = array.size();
        if (m==0) return {};
        const int n = array[0].size();
        if (n==0) return {};

        std::vector<int> ans;
        // 可在构造 ans 前执行 ans.reserve(m * n) 以避免多次扩容
        ans.reserve(m*n);

        int top = 0, bottom = m-1, left = 0, right = n-1;
        while (top<=bottom && left<=right) {
            for (int i=left; i<=right; ++i) {
                ans.push_back(array[top][i]);
            }
            for (int i=top+1; i<=bottom; ++i) {
                ans.push_back(array[i][right]);
            }
            if (left < right && top < bottom) {
                for (int i=right-1; i>=left; --i) {
                    ans.push_back(array[bottom][i]);
                }
                for (int i=bottom-1; i>top; --i) {
                    ans.push_back(array[i][left]);
                }
            }
            
            ++top;
            ++left;
            --bottom;
            --right;
        }
        
        
        return ans;
    }
};