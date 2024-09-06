#include <unordered_map>
#include <vector>

using std::vector;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> map1;  // 元素值 : 出现次数
        for(const int& e: arr)
        {
            map1[e]++;
        }
        std::unordered_map<int, int> map2;
        for(const auto& e: map1)    // 元素出现次数 : 次数的出现次数
        {
            map2[e.second]++;
            if(map2[e.second]>=2)
                return false;
        }
        return true;
    }
    bool uniqueOccurrences2(vector<int>& arr) {
        // std::unordered_map<int, int> map1;  // 元素值 : 出现次数
        int map1[2001] = { 0 };
        for(const int& e: arr)
        {
            map1[e+1000]++;
        }
        // std::unordered_map<int, int> map2;  // 元素出现次数 : 次数的出现次数
        int map2[1001] = { 0 };
        for(const int& e: map1)    
        {
            if(e){  // 默认的0次不算
                map2[e]++;
                if(map2[e]>=2)
                    return false;
            }
            // map2[e.second]++;
            // if(map2[e.second]>=2)
            //     return false;
        }
        return true;
    }
};