#include "../../utils/utils.h"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): _sz(size), _sum(0) {
    }
    
    double next(int val) {
        _que.push(val);
        if (_que.size()>_sz) {
            _sum -= _que.front();
            _que.pop();
        }
        _sum += val;
        return (double)_sum/_que.size();
    }
private:
    std::queue<int> _que;
    int _sz;
    int _sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */