#include <string>
#include <vector>
#include <stack>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 辅助栈
        std::stack<int> helper_stack;

        for (const string& s : tokens) {
            // 是否是运算符
            if (isOperator(s)) {
                // 弹出栈顶2个元素
                // 假设输入逆波兰式都有效
                int left = helper_stack.top();
                helper_stack.pop();
                int right = helper_stack.top();
                helper_stack.pop();
                
                int tmp = 0;
                if (s=="+") {
                    tmp = left + right;
                }
                else if (s=="-") {
                    tmp = right-left;
                }
                else if (s=="*") {
                    tmp = left*right;
                }
                else if (s=="/") {
                    tmp = right/left;
                }
                // std::cout<<"运算结果："<<tmp<<std::endl;
                helper_stack.push(tmp);

            } else {
                // 转化为数字
                helper_stack.push(std::stoi(s));
            }
        }
        return helper_stack.top();
    }

    bool isOperator(const string& s){
        if (s=="+" || s=="-" || s=="*" || s=="/") {
            return true;
        }
        return false;
    }
};

int main() {
    std::vector<string> tokens = {"4","13","5","/","+"};
    Solution test;
    int res = test.evalRPN(tokens);
    std::cout<<"result："<<res<<std::endl;

    return 0;
}