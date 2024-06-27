#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;

class Solution {
public:

    // O(n log m + k n)
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int num_neg=0;
        int sum = 0;
        int zeroIndex = -1;
        // 小跟堆，用于存储负数
        std::priority_queue<int, vector<int>, std::greater<int>> minHeap;

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]<0) {
                ++num_neg;
                minHeap.push(nums[i]);
            } else if (nums[i]==0) {
                zeroIndex=i;
            }
        }
        if (k<=num_neg) {
           // 取出小根堆中最小的k个负数，并将其取反
           for (int i = 0; i<k; ++i) {
                int smallestNeg = minHeap.top();
                minHeap.pop();
                auto it = std::find(nums.begin(), nums.end(), smallestNeg);
                if (it != nums.end()) {
                    *it = -(*it);
                }
           }
        } else {
            // 所有负数取反
            for (int& num : nums) {
                    if (num<0) {
                        num = -num;
                    }
                }
            if(zeroIndex==-1) { // 无0
                if ((k-num_neg)%2==1) { // 奇数
                    int minIndex = 0;
                    for (int i=1; i<nums.size(); ++i) {
                        if (nums[i]<nums[minIndex]) {
                            minIndex=i;
                        }
                    }
                    nums[minIndex]=-nums[minIndex];
                } 
            }
        }
        for (const int& num : nums) {
            sum+=num;
        }
        return sum;

    }

    // 比较函数：按照绝对值从大到小排序
    bool static compareAbsoluteValueDesc(int a, int b) {
        return std::abs(a) > std::abs(b);
    }

    // O(n log n)
     int largestSumAfterKNegations1(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), compareAbsoluteValueDesc);
        for (int& num : nums) {
            if (num<0 && k>0) {
                num=-num;
                --k;
            }
        }
        if (k>0) {
            if (k%2==1) {
                nums[nums.size()-1]*=-1;
            }
        }
        int sum=0;
        for (const int& num : nums) {
            sum+=num;
        }
        return sum;

    }
};