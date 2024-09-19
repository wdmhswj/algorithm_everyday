#include <iostream>
#include <queue>

int main()
{
    int n=-1;
    int p=-1;
    int m=-1;
    std::queue<int> que;

    while (std::cin>>n>>p>>m) {
        if(n==0 && p==0 && m==0)
            break;
        while (!que.empty()) {
            que.pop();
        }

        for(int i=p; i<=n; i++)
            que.push(i);
        for(int i=1; i<p; i++)
            que.push(i);
        
        int k = 1;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            if(k==m)
            {
                if(que.empty())
                    std::cout<<cur<<std::endl;
                else std::cout<<cur<<",";
                k=1;
            }else{
                ++k;
                que.push(cur);
            }
        }
    }
    return 0;
}