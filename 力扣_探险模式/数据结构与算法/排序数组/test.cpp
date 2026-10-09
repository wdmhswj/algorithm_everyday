#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        for (int i=n/2-1; i>=0; --i) {
            ShiftDown(nums, n, i); // 自底向上构造大根堆
        }
        for (int i=n-1; i>=0; --i) {
            mySwap(nums[i], nums[0]); // 堆顶为最大值
            ShiftDown(nums, i, 0); // 将 [0, i-1] 重构为大根堆
        }
        return nums;
    }
private:
    void ShiftDown(std::vector<int>& nums, int len, int i) {
        while (true) {
            int largest = i;
            int left = 2*i+1;
            int right = 2*i+2;
            if (left<len && nums[left]>nums[largest]) {
                largest = left;
            }
            if (right<len && nums[right]>nums[largest]) {
                largest = right;
            }
            if (largest==i) break; // 当前层满足大根堆
            mySwap(nums[i], nums[largest]);
            i = largest; // 继续判断子节点
        }
    }
    void mySwap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};


int main() {
    
    return 0;
}