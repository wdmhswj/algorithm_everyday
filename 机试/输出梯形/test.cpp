#include <iostream>

int main()
{
    int h=-1;
    std::cin>>h;
    for(int i=0; i<h; ++i)
    {
        for(int j=0; j<h+i; ++j)
        {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    for(int i=0; i<h; ++i)
    {
        for(int j=0; j<h-1-i; ++j)
        {
            std::cout<<" ";
        }
        for(int j=0; j<h+i; ++j)
        {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }


    return 0;
}