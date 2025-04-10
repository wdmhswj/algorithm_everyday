#include <vector>
#include <unordeored_map>
#include <algorithm>

using std::vector;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); ++i) {
            m_map[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(m_map.find(value) == m_map.end())
            return 0;
        int count = 0;
        for(auto index: m_map[value]) {
            if(index>=left && index<=right)
                ++count;
        }
        return count;
    }
    int query_1(int left, int right, int value) {
        const vector<int>& pos = m_map[value];
        auto l = std::lower_bound(pos.begin(), pos.end(), left);
        auto r = std::upper_bound(pos.begin(), pos.end(), right);
        return r-l;
    }
private:
    std::unordered_map<int, std::vector<int>> m_map;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */