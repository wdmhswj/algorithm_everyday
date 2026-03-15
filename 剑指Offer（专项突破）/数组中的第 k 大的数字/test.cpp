#include "../../utils/utils.h"

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        return _quickSelect(nums, 0, n-1, n-k);
    }

    int findKthLargest_1(std::vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.end()-k, nums.end());
        return nums[nums.size()-k];
    }

    int findKthLargest_2(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // 小根堆
        for (int num: nums) {
            minHeap.push(num);
            if (minHeap.size()>k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
private:
    int _quickSelect(std::vector<int>& nums, int left, int right, int targetElementIndex) {
        if (left==right) return nums[left];
        int pivotIndex = left + rand() % (right-left+1);
        std::swap(nums[pivotIndex], nums[right]);
        int finalPivotIndex = _partion(nums, left, right);
        if (finalPivotIndex==targetElementIndex) return nums[targetElementIndex];
        else if (finalPivotIndex<targetElementIndex) return _quickSelect(nums, finalPivotIndex+1, right, targetElementIndex);
        else return _quickSelect(nums, left, finalPivotIndex-1, targetElementIndex);
    }

    int _partion(std::vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j=left; j<right; ++j) {
            if (nums[j]<=pivot) {
                std::swap(nums[j], nums[i]);
                ++i;
            }
        }
        std::swap(nums[i], nums[right]);
        return i;
    }
};