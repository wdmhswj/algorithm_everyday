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
    int src=0, dst=0, k=0;
    std::cin>>src>>dst>>k;

    std::vector<int> dist(n+1, INF);
    std::vector<int> dist_copy;
    
    dist[src]=0;
    // k+1 次松弛
    for(int i=0; i<k+1; i++)
    {
        dist_copy = dist;
        for(const Edge& e: edges)
        {
            if (dist_copy[e.u]!=INF && dist[e.v]>dist_copy[e.u]+e.weight) {
                dist[e.v] = dist_copy[e.u] + e.weight;
            }
        }
    }

    if (dist[dst]==INF) {
        std::cout<<"unreachable";
    } else {
        std::cout<<dist[dst];
    }
    return 0;
}

