#include <iostream>
#include <limits>
#include <vector>

struct Edge{
    int u, v, weight;
};

const int INF = std::numeric_limits<int>::max();

int main()
{
    int n=0, m=0;
    std::cin>>n>>m;
    std::vector<Edge> edges(m);
    for(int i=0; i<m; ++i)
    {
        std::cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    }

    std::vector<int> dist(n+1, INF);

    int start = 1, end = n;
    dist[start]=0;
    // V-1 次松弛
    for(int i=1; i<n; i++)
    {
        for(const Edge& e: edges)
        {
            if (dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.weight) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }
    // 第V次进行检查负环
    for(const Edge& e: edges)
    {
        if (dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.weight) {
            std::cout<<"circle";
            return 0;
        }
    }

    if (dist[end]==INF) {
        std::cout<<"unconnected";
    } else {
        std::cout<<dist[n];
    }
    return 0;
}

