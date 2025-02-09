#include <vector>
#include <iostream>
#include "../../utils/printH.h"
using std::vector;

class Solution {
public:
    // O( (m+n)*n ), O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_1 = 0;   
        int index_2 = 0;
        int m_end = m;  
        while(index_1 < m_end && index_2 < n) {
            if(nums1[index_1] <= nums2[index_2]) {
                ++index_1;
            } else {
                // 将 nums2[index_2] 插入的 nums1[index_1] 的位置
                nums1.insert(nums1.begin()+index_1, nums2[index_2]);
                ++index_2;
                ++index_1;
                ++m_end;
            }
            // std::cout << "index_1 = " << index_1 << ", index_2 = " << index_2 << ", m_end = " << m_end << std::endl;
            // printVector1D(nums1);
            // printVector1D(nums2);
        }
        if(index_2 < n) {   // nums2 未排完
            while(index_2 < n) {
                nums1[index_1] = nums2[index_2];
                ++index_1;
                ++index_2;
            }
        }
        nums1.resize(m+n);
    }

    // O(m+n), O(1)
    void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_1 = m - 1;  // nums1的有效元素的最后一个索引
        int index_2 = n - 1;  // nums2的最后一个索引
        int merge_index = m + n - 1;  // 合并后数组的最后一个位置

        // 从后往前合并
        while(index_1 >= 0 && index_2 >= 0) {
            if(nums1[index_1] > nums2[index_2]) {
                nums1[merge_index] = nums1[index_1];
                --index_1;
            } else {
                nums1[merge_index] = nums2[index_2];
                --index_2;
            }
            --merge_index;
        }

        // 如果 nums2 还有剩余，复制到 nums1 前面
        while(index_2 >= 0) {
            nums1[merge_index] = nums2[index_2];
            --index_2;
            --merge_index;
        }

        // nums1 的剩余部分如果有，已经在原位置，不需要做任何操作
    }

    // 添加额外数组存放排序后的结果：O(m+n), O(m+n)
};


int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for(const int& i: nums1) {
        std::cout << i << " ";
    }
}