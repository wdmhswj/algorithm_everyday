#include <iostream>
#include <vector>


// 寻找根节点
int find(int u, std::vector<int>& father)
{
    return u==father[u] ? u : father[u]=find(father[u], father);    // 路径压缩
}

// 判断2个节点的根节点是否相同
bool isSameRoot(int u, int v, std::vector<int>& father)
{
    // int r_u = find(u, father);
    // int r_v = find(v, father);
    return find(u, father)==find(v, father);
}

// 使右边节点的根节点为左边节点的根节点
void join(int u, int v, std::vector<int>& father)
{
    int r_u = find(u, father);
    int r_v = find(v, father);
    if(r_u==r_v)    return;
    else father[r_v]=r_u;
}

int main()
{
    // 读取输入
    int M=0, N=0;
    std::cin>>N>>M;
    std::vector<int> father(N+1, 0);

    // 初始化：根节点为自身
    for(int i=1; i<=N; i++)
        father[i]=i;

    // 合并
    int s=-1, t=-1;
    for(int i=0; i<M; i++)
    {
        std::cin>>s>>t;
        join(s, t, father);
    }

    int source = -1, destination = -1;
    std::cin>>source>>destination;
    if (isSameRoot(source, destination, father)) {
        std::cout<<1;
    }else {
        std::cout<<0;
    }

    return 0;
}