#include "../../utils/utils.h"

class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1_.push(value);
    }
    
    int deleteHead() {
        int tmp = -1;
        if (!s2_.empty()) {
            tmp = s2_.top();
            s2_.pop();
            return tmp;
        }
        if (s1_.empty()) return tmp;
        while (!s1_.empty()) {
            tmp = s1_.top();
            s1_.pop();
            s2_.push(tmp);
        }
        s2_.pop();
        return tmp;
    }
private:
    std::stack<int> s1_;
    std::stack<int> s2_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
    std::stack<int> s;
    s.pop();
}