#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i=0; i<k; ++i) {
            pq.push(nums[i]);
        }
        for (int i=k; i<nums.size(); ++i) {
            pq.push(nums[i]);
            while (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }

    int findKthLargest(vector<int>& nums, int k) {
        std::srand(std::time(nullptr)); // 初始化随机种子
        const int n = nums.size();
        int target_idx = n-k;
        int left = 0, right = n-1;
        while (true) {
            int i = partion(nums, left, right);
            if (i == target_idx) {
                return nums[i];
            } else if (i < target_idx) {
                left = i+1;
            } else {
                right = i-1;
            }
        }

    }

    int findKthLargest(vector<int>& nums, int k) {
        std::ranges::nth_element(nums, nums.end()-k);
        return nums[nums.size()-k];
    }
private:
    int partion(std::vector<int>& nums, int left, int right) {
        int i = left + std::rand() % (right-left+1); // [left, right]的随机数
        int pivot = nums[i];
        std::swap(nums[i], nums[left]); // 简化交换逻辑
        i = left+1;
        int j = right;
        while (true) {
            while (i<=j && nums[i]<pivot) {
                ++i;
            }
            // nums[i]>=pivot
            while (i<=j && nums[j]>pivot) {
                --j;
            }
            // nums[j]<=pivot
            if (i>=j) break;
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
        std::swap(nums[left], nums[j]);
        return j;
    }
};

int main() {
    
    return 0;
}