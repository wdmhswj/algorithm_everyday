#include <iostream>

int main(){

    // int a=-1, b=-1, c=-1;
    int abc=-1, bcc=-1;
    for(int a=1; a<=9; ++a)
    {
        for(int b=1; b<=9; ++b)
        {
            for(int c=0; c<=9; ++c)
            {
                abc = a*100 + b*10 + c;
                bcc = b*100 + c*10 + c;
                int sum = abc+bcc;
                // std::cout<<"sum="<<sum<<std::endl;
                if(sum == 532)
                {
                    std::cout<<a<<" "<<b<<" "<<c<<std::endl;
                }
            }
        }
    }
    return 0;
}