#include <queue>

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
       helperQue.push(x);
    }
    
    int pop() {
       int size = helperQue.size();
        for (int i=0; i<size-1; ++i) {
            int front = helperQue.front();
            helperQue.push(front);
            helperQue.pop();
        }
        int res = helperQue.front();
        helperQue.pop();
        return res;
    }
    
    int top() {
        return helperQue.back();
    }
    
    bool empty() {
        return helperQue.empty();
    }
private:
    std::queue<int> helperQue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */