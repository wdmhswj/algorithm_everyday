// #include <algorithm>
#include <iostream>
#include <stack>
#include <string>
// #include <utility>
#include <vector>

int main()
{
    std::string line;   
    std::stack<int> st;

    while(std::cin>>line)
    {
        while (!st.empty()) {
            st.pop();
        }
        std::string output(line.size(), ' ');
        std::vector<int> vec;
        for(int i=0; i<line.size(); ++i){
            if(line[i]=='('){
                st.push(i);
                // std::cout<<" ";
            }else if(line[i]==')'){
                if(!st.empty()){
                    st.pop();
                    // std::cout<<" ";
                }else {
                    output[i]='?';
                };
            }else{
                // std::cout<<" ";
            }
        }
        while (!st.empty()) {
            output[st.top()]='$';
            st.pop();
        }
        
        std::cout<<output<<std::endl;
    }
    return 0;
}