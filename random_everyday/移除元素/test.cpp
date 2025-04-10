#include <vector>
#include <iostream>
#include "../../utils/printH.h"
using std::vector;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(size_t i=0; i<nums.size(); ++i) {
            if(nums[i]==val) {
                ++count;
            } else {
                nums[i-count] = nums[i];
            }
        }
        return nums.size()-count;
    }
    int removeElement_1(vector<int>& nums, int val) {
        int count = 0;
        size_t l = 0;
        for(size_t i=0; i<nums.size(); ++i) {
            if(nums[i]==val) {
                ++count;
            } else {
                nums[l] = nums[i];
                ++l;
            }
        }
        return nums.size()-count;
    }
};

int main() {
    vector<vector<int>> vecs = {
        {3,2,2,3},
        {0,1,2,2,3,0,4,2}
    };
    vector<int> values = {
        3, 2
    };
    int index = 0;
    for(auto& nums: vecs) {
        std::cout << "before" << std::endl;
        printVector1D(nums);
        Solution s;
        int k = s.removeElement_1(nums, values[index]);
        std::cout << "k = " << k << std::endl;
        std::cout << "after" << std::endl;
        printVector1D(nums);
        ++index;
    }
};