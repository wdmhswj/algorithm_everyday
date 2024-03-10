#include<stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        // 如果栈2不为空，直接pop栈首，如果为空，将栈1所有元素转移到栈2
        if(stack2.empty()){ 
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }   
        }
        int res=stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};