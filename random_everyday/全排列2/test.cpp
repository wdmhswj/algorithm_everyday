#include <vector>
#include <map>
#include <iostream>
using std::vector;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::map<int, unsigned int> l_map;
        for(const int& i: nums) {
            l_map[i]++;
        }
        vector<vector<int>> res;
        vector<int> vec;
        permute(res, l_map, vec, nums.size());
        return res;
    }

private:
    void permute(vector<vector<int>>& res, std::map<int, unsigned int>& l_map, vector<int>& vec, size_t n) {
        if(vec.size() == n) {
            res.push_back(vec);
            return;
        }
        
        for(auto& pair: l_map) {
            if(pair.second == 0) 
                continue;
            vec.push_back(pair.first);
            pair.second--;
            permute(res, l_map, vec, n);
            pair.second++;
            vec.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {2,2,2};
    Solution s;
    auto res = s.permuteUnique(nums);
    for(auto& vec: res) {
        for(auto& i: vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}