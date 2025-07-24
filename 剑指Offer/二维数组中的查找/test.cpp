#include "../../utils/utils.h"

class Solution {
public:
    // 暴力二分查找
    bool findTargetIn2DPlants(std::vector<std::vector<int>>& plants, int target) {

        const int n = plants.size();
        if (n==0) return false;
        const int m = plants[0].size();
        if (m==0) return false;
        
        int index = 0;
        for (int i=0; i<n; ++i)
        {
            int begin=0, end=m-1;
            while (begin <= end) {
                index = begin + (end-begin)/2;
                if (plants[i][index]==target)
                    return true;
                else if (plants[i][index]<target)
                    begin = index+1;
                else
                    end = index-1;
            }
        }
        return false;
    }

    // 从左下角或右上角开始
    bool findTargetIn2DPlants_1(std::vector<std::vector<int>>& plants, int target) {
        const int n = plants.size();
        if (n==0) return false;
        const int m = plants[0].size();
        if (m==0) return false;

        int i=n-1, j=0;
        while (i>=0 && j<=m-1) {
            if (plants[i][j]==target)
                return true;
            else if (target<plants[i][j])
                --i;
            else
                ++j;
        }
        return false;
    }
};