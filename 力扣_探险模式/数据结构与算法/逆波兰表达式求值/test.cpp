#include "../../../utils/utils.h"

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        int res = 0;
        for (const std::string& tok: tokens) {
            std::cout << "tok=" << tok << std::endl;
            if (_isOp(tok)) {
                int op1=0, op2=0;
                if (!stk.empty()) {
                    op2 = stk.top(); stk.pop();
                } else {
                    return -1;
                }
                if (!stk.empty()) {
                    op1 = stk.top(); stk.pop();
                } else {
                    return -1;
                }
                if (tok[0]=='+') {
                    res = op1 + op2;
                } else if (tok[0]=='-') {
                    res = op1 - op2;
                } else if (tok[0]=='*') {
                    res = op1 * op2;
                } else if (tok[0]=='/') {
                    res = op1 / op2;
                }
                std::cout << "res=" << res << std::endl;
                stk.push(res);
            } else {
                stk.push(std::stoi(tok));
            }
            std::cout << "-----------------------------\n";
        }
        return stk.top();
    }

    int evalRPN(const std::vector<std::string>& tokens) {
        // 使用连续内存 vector 预分配，或者使用基于栈大小的数组模拟栈
        std::vector<long long> stk((tokens.size() + 1) / 2);
        int top = -1;

        for (const std::string& tok : tokens) {
            // 如果长度为1且不是数字，则一定是运算符
            if (tok.size() == 1 && (tok[0] < '0' || tok[0] > '9')) {
                long long op2 = stk[top--];
                long long op1 = stk[top--];

                switch (tok[0]) {
                    case '+': stk[++top] = op1 + op2; break;
                    case '-': stk[++top] = op1 - op2; break;
                    case '*': stk[++top] = op1 * op2; break;
                    case '/': stk[++top] = op1 / op2; break;
                }
            } else {
                // 手写极速 stoi（处理可选的负号）
                long long num = 0;
                bool negative = (tok[0] == '-');
                size_t i = (negative || tok[0] == '+') ? 1 : 0;
                for (; i < tok.size(); ++i) {
                    num = num * 10 + (tok[i] - '0');
                }
                stk[++top] = negative ? -num : num;
            }
        }
        return stk[0];
    }

private:
    bool _isOp(const std::string& tok) {
        return tok.size()==1 && (tok[0]=='+' || tok[0]=='-' || tok[0]=='*' || tok[0]=='/');
    }
};

int main() {
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    std::cout << s.evalRPN(tokens);

    return 0;
}