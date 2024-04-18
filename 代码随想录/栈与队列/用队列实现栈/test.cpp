#include <queue>

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        if (!mainQue.empty()) {
            int top = mainQue.front();
            helperQue.push(top);
            mainQue.pop();
        }
        mainQue.push(x);
    }
    
    int pop() {
        int res = mainQue.front();
        mainQue.pop();

       
        while (!helperQue.empty()) {
            int front = helperQue.front();
            mainQue.push(front);
            helperQue.pop();
        }
        int num = mainQue.size();
        for(int i=0; i<num-1; ++i){
            int front = mainQue.front();
            helperQue.push(front);
            mainQue.pop();
        }

        return res;
    }
    
    int top() {
        int res = mainQue.front();
        return res;
    }
    
    bool empty() {
        return mainQue.empty() && helperQue.empty();
    }
private:
    std::queue<int> mainQue;
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