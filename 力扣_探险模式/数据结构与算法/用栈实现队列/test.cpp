#include "../../../utils/utils.h"

// push(1,2,3,4), pop


class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        _stk0.push(x);
    }
    
    int pop() {
        int top = this->peek();
        _stk1.pop();
        return top;
    }
    
    int peek() {
        int top = 0;
        if (!_stk1.empty()) {
            return _stk1.top();
        }

        while (!_stk0.empty()) {
            top = _stk0.top(); _stk0.pop();
            _stk1.push(top);
        }
        top = _stk1.top();
        return top;
    }
    
    bool empty() {
        return _stk0.empty() && _stk1.empty();
    }

private:
    std::stack<int> _stk0;
    std::stack<int> _stk1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */