#include "../../utils/utils.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _stk2.push(INT_MAX);
    }
    
    void push(int x) {
        _stk1.push(x);
        _stk2.push(std::min(x, _stk2.top()));
    }
    
    void pop() {
        _stk1.pop();
        _stk2.pop();
    }
    
    int top() {
        return _stk1.top();
    }
    
    int getMin() {
        return _stk2.top();
    }
private:
    std::stack<int> _stk1;
    std::stack<int> _stk2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */