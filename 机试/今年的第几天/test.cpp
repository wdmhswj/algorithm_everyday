#include <iostream>

int main()
{
    int mday[12] = {
        31,
        28,
        31,
        30, 
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31,
    };
    int today[12] = {0};
    today[0] = 0;
    for(int i=1; i<12; ++i)
    {
        today[i] = today[i-1] + mday[i-1];
    }

    int year = -1;
    int month = -1;
    int day = -1;

    while(std::cin>>year>>month>>day) {
        // 判断闰年
        if(month>=3 && (year%400==0 || year%100!=0&&year%4==0))
        {
            std::cout<<today[month-1]+day+1<<std::endl;
        }else{
            std::cout<<today[month-1]+day<<std::endl;
        }
    }
    return 0;
}