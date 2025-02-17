#include <vector>
#include "../../utils/printH.h"
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> L(n), R(n);
        L[0] = 1;
        R[n-1] = 1;
        for(int i=1; i<n; ++i) {
            L[i] = L[i-1]*nums[i-1];
        }
        for(int i=n-2; i>=0; --i) {
            R[i] = R[i+1]*nums[i+1];
        }
        vector<int> res;
        for(int i=0; i<n; ++i) {
            res.push_back(L[i]*R[i]);
        }
        return res;
    }
    vector<int> productExceptSelf_1(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        res[0] = 1;
        for(int i=1; i<n; ++i) {
            res[i] = res[i-1]*nums[i-1];
        }
        int R = 1;
        for(int i=n-1; i>=0; --i) {
            res[i] = res[i]*R;
            R*=nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums {
        1,2,3,4
    };
    Solution s;
    auto rt = s.productExceptSelf_1(nums);
    printVector1D(rt);
}