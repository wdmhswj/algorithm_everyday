#include "../../utils/utils.h"

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        
        for (const std::string& s: tokens) {
            char op = 't';
            int d = 0;
            if (s[0]=='-' && s.size() > 1 || s[0]>='0' && s[0]<='9') {
                // 转换为数字
                int flag = 1;
                for (int i=0; i<s.size(); ++i) {
                    if (i==0 && s[i]=='-')
                        flag = -1;
                    else 
                        d = d*10 + (s[i]-'0');
                }
                st.push(d*flag);
            } else if (s=="+") {
               op = '+';
            } else if (s=="-") {
               op = '-';
            } else if (s=="*") {
               op = '*';
            } else if (s=="/") {
               op = '/';
            } else
                return -1;
            std::cout << "op: " << op << std::endl;
            if (op != 't') {
                int l=0, r=0;
                if (!st.empty()){
                    r = st.top();
                    st.pop();
                } else
                    return -1;
                if (!st.empty()){
                    l = st.top();
                    st.pop();
                } else
                    return -1;
                std::cout << "l: " << l << ", r: " << r << ", op: " << op << std::endl;
                switch (op)
                {
                case '+':
                    d = l+r;
                    break;
                case '-':
                    d = l-r;
                    break;
                case '*':
                    d = l*r;
                    break;
                case '/':
                    d = l/r;
                    break;
                default:
                    break;
                }
                st.push(d);
            }
            
        }
        int ret = -1;
        if (!st.empty())
            ret = st.top();
        return ret;
    }

    int evalRPN1(std::vector<std::string>& tokens) {
        std::stack<int> st;
        
        for (const std::string& s: tokens) {
            if (s.size()>1 || std::isdigit(s[0])) {
                st.push(std::stoi(s));
            } else {
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                if (s[0]=='+')
                    st.push(l+r);
                else if (s[0]=='-')
                    st.push(l-r);
                else if (s[0]=='*')
                    st.push(l*r);
                else if (s[0]=='/')
                    st.push(l/r);
            }
        }
        int ret = -1;
        if (!st.empty())
            ret = st.top();
        return ret;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tokens = {"4","3","-"};
    int ret = sol.evalRPN(tokens);
    std::cout << ret << std::endl;
}