#include <map>
#include <stack>
#include <string>
using std::string;

class Solution {
public:
    bool isValid(string s) {
        // 字符数若为奇数，则必然无效
        if (s.size()%2 != 0) {
            return false;
        }

        // 辅助栈
        std::stack<char> helper_stack;
        std::map<char, char> helper_map = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };

        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') { // 左括号
                helper_stack.push(helper_map[c]);
            }else if (helper_stack.empty() || helper_stack.top()!=c) {  // 栈为空或栈顶不等于当前字符，则无效
                return false;
            }else {
                helper_stack.pop(); // 栈顶字符等于当前字符（匹配成功）
            }
        }
        return helper_stack.empty();    // 判断是否有左括号没有匹配到

    }
};