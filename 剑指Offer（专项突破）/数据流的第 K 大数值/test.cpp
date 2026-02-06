#include "../../utils/utils.h"


class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        _k = k;
        for (const int& e: nums)
            _pq.push(e);
        while (_pq.size()>_k)
            _pq.pop();
    }
    
    int add(int val) {
        _pq.push(val);
        if (_pq.size()>_k) _pq.pop();
        return _pq.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> _pq;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */