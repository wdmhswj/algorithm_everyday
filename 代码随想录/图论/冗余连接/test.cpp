#include <iostream>
#include <vector>

int find(int u, std::vector<int>& father)
{
    return u==father[u] ? u : father[u]=find(father[u], father);
}

bool isSameRoot(int u, int v, std::vector<int>& father)
{
    return find(u, father)==find(v, father);
}

void join(int u, int v, std::vector<int>& father)
{
    int r_u = find(u, father);
    int r_v = find(v, father);
    if(r_u==r_v) return;
    else father[r_v]=r_u;
}


int main()
{
    int N=0;
    std::cin>>N;
    std::vector<int> father(N+1, 0);
    // 初始化
    for(int i = 1; i<=N; i++)
    {
        father[i]=i;
    }
    int s=-1, t=-1;
    int s_l=-1, t_l=-1;
    for(int i=0; i<N; i++)
    {
        std::cin>>s>>t;
        if(isSameRoot(s, t, father))
        {
            s_l=s;
            t_l=t;
        }
        join(s, t, father);
    }
    std::cout<<s_l<<" "<<t_l;

    return 0;
}