// #include <stack>
#include <string>
using std::string;

class Solution {
public:
    string clearDigits(string s) {
        while(true){
            int index_d=-1;
            for(int i=0; i<s.size(); ++i){
                if(isDigit(s[i]))
                {
                    index_d=i;
                    break;
                }
            }
            if(index_d==-1)
                return s;
            if(index_d==0)
                s.erase(0, 1);
            else
                s.erase(index_d-1, 2);
        }
    }

    // 用栈维护(std::string也可以实现栈操作)
    string clearDigits2(string s) {
        string st;
        for(const char& c: s)
        {
            if (c>='0' && c<='9') {
                st.pop_back();
            }else {
                st.push_back(c);
            }
        }
        return st;
    }
private:
    bool isDigit(const char& c){
        return c>='0' && c<='9';
    }
};