#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> idxMap;
        for (int i=0; i<nums.size(); ++i) {
            if (idxMap.count(target-nums[i])) {
                return {i, idxMap[target-nums[i]]};
            }
            idxMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    
    return 0;
}