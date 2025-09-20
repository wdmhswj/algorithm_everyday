#include "../../utils/utils.h"


class Checkout {
public:
    Checkout() {
        
    }
    
    int get_max() {
        return q2.empty() ? -1 : q2.front();
    }
    
    void add(int value) {
        while (!q2.empty() && q2.back()<value)
        {
            q2.pop_back();
        }
        q2.push_back(value);
        q1.push_back(value);
    }
    
    int remove() {
        if (q1.empty()) return -1;
        if (q2.front()==q1.front()) q2.pop_front();
        int rt = q1.front();
        q1.pop_front();
        return rt;
    }
private:
    std::deque<int> q1;
    std::deque<int> q2;
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */