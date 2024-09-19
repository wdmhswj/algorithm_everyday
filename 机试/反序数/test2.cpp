#include <iostream>

int main()
{
    // int x1=1;
    for(int x1=1; x1<=9; ++x1)
    {
        for(int x2=0; x2<=9; ++x2)
        {
            for(int x3=0; x3<=9; ++x3)
            {
                for(int x4=1; x4<=9; ++x4)
                {
                    int t = x1*1000 + x2*100 + x3*10 + x4;
                    int t_ = x1 + x2*10 + x3*100 + x4*1000;
                    if(t_-t*9==0)
                    {
                        std::cout<<t<<std::endl;
                    }
                }
            }
        }
    }
    
    return 0;
}