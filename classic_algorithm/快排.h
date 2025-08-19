/*
    * @file 快排.h
    * @brief 快速排序算法实现
    * @version 1.0
    * @date 2025-8-19
    *
    * @note 该文件包含快速排序算法的实现，使用C++17标准。
*/

#include <algorithm>
#include <iostream>
#include <vector>
#
class quickSort {

public:

    void sort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            sort(arr, left, pivotIndex - 1);
            sort(arr, pivotIndex + 1, right);
        }
    }
private:

    int partition(std::vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j=left; j<right; ++j) {
            if (arr[j]<pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i+1], arr[right]);
        return i+1;
    }
};