#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, bool> seen;
        const int n = nums.size();
        if (n<2) return false;
        
        for (int i=0; i<=k && i<n; ++i) {
            if (seen[nums[i]]) return true;
            seen[nums[i]] = true;
        }
        if (n<=k) return false;

        for (int i=k+1; i<n; ++i) {
            seen[nums[i-k-1]] = false;
            if (seen[nums[i]]) return true;
            seen[nums[i]] = true;
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;
        for (int i=0; i<nums.size(); ++i) {
            if (i>k) window.erase(nums[i-k-1]);
            if (window.count(nums[i])) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};


int main() {
    
    return 0;
}