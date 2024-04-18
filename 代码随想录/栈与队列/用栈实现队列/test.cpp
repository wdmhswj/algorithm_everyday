#include <stack>

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        int res = peek();
        stackOut.pop();
        return res;
    }
    
    int peek() {
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int res = stackOut.top();
        return res;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
private:
    std::stack<int> stackIn;
    std::stack<int> stackOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */