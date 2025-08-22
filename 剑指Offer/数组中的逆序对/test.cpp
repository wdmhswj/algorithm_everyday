#include "../../utils/utils.h"

class Solution {
public:
    int reversePairs(std::vector<int>& record) {
        const int n = record.size();
        if (n<=1) return 0;
        int rt = 0;
        for (int i=0; i<n-1; ++i) {
            int tmp = 0;
            for (int j=i+1; j<n; ++j) {
                if (record[i]>record[j]) ++tmp;
            }
            rt += tmp;
        }
        return rt;
    }


    int reversePairs1(std::vector<int>& record) {
        const int n = record.size();
        if (n<=1) return 0;

        std::vector<int> tmp(n, 0);

        std::function<int(int, int)> mergeSort = [&](int l, int r) -> int {
            if (l>=r) return 0;
            int mid = l + (r-l)/2;
            int rt = mergeSort(l, mid) + mergeSort(mid+1, r);
            int i=l, j=mid+1, k=0;
            while (i<=mid && j<=r) {
                if (record[i] <= record[j]) {
                    tmp[k++] = record[i++];
                } else {
                    rt += (mid-i+1);
                    tmp[k++] = record[j++];
                }
            }
            while (i<=mid) {
                tmp[k++] = record[i++];
            }
            while (j<=r) {
                tmp[k++] = record[j++];
            }
            for (int i=l; i<=r; ++i) {
                record[i] = tmp[i-l];
            }
            return rt;
        };

        return mergeSort(0, n-1);
    }
};