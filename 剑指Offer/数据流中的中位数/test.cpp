#include "../../utils/utils.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        _maxQ.push(num);
        _minQ.push(_maxQ.top());
        _maxQ.pop();
        if (_minQ.size()-_maxQ.size() > 1) {
            _maxQ.push(_minQ.top());
            _minQ.pop();
        }
    }
    
    double findMedian() {
        return _minQ.size()==_maxQ.size() ? (_minQ.top()+_maxQ.top())/2.0 : _minQ.top();
    }
private:
    std::priority_queue<int> _maxQ;
    std::priority_queue<int, std::vector<int>, std::greater<int>> _minQ;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */