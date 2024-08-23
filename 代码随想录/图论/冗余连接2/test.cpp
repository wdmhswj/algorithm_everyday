#include <iostream>
#include <utility>
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
    std::vector<std::pair<int, int>> edges;
    int redundantEdgeIndex = -1, firstParentEdgeIndex=-1;
    for(int i=0; i<N; i++)
    {
        std::cin>>s>>t;
        edges.push_back({s, t});
        // 判断t节点是否已经有父节点了
        if(father[t]!=t)
        {
            firstParentEdgeIndex = i;
        }else if(isSameRoot(s, t, father))  // 是否形成有向环
        {
            redundantEdgeIndex = i;
        }else {
            join(s, t, father);
        }
        
    }
    std::cout<<"firstParentEdgeIndex="<<firstParentEdgeIndex<< " redundantEdgeIndex="<<redundantEdgeIndex<<std::endl;;

    // 是否有入度为2
    if(firstParentEdgeIndex!=-1)
    {
        // 是否同时形成有向环
        if(redundantEdgeIndex!=-1)
        {
            for (int i=0; i<N; ++i) {
                if (edges[i].second == edges[firstParentEdgeIndex].second) {
                    std::cout << edges[i].first << " " << edges[i].second << std::endl;
                    break;
                }
            }
        }else{
            std::cout<<edges[firstParentEdgeIndex].first << " " <<edges[firstParentEdgeIndex].second;
        }
    }else{
        std::cout<<edges[redundantEdgeIndex].first << " " <<edges[redundantEdgeIndex].second;
    }
    
    return 0;
}