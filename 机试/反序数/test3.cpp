#include <iostream>

// 求反序数
int Reverse(int n)
{
    int reverse = 0;
    int remain;
    while(true)
    {
        remain = n%10;
        reverse = reverse*10 + remain;
        n /= 10;
        if(n==0)
            break;
    }
    return reverse;
}

int main()
{
    for(int i=0; i<=256; ++i)
    {
        if(i*i == Reverse(i*i))
        {
            std::cout<<i<<std::endl;
        }
    }
}