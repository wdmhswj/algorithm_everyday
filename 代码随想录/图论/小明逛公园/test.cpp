#include <iostream>
#include <limits>
#include <utility>
#include <vector>

struct Edge {
    int u, v, w;
};

const int INF = std::numeric_limits<int>::max();

int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<Edge> edges(M);
    for(auto& e: edges)
    {
        std::cin>>e.u>>e.v>>e.w;
    }
    int Q=0;
    std::cin>>Q;
    std::vector<std::pair<int, int>> schedule(Q);
    for(auto& pair: schedule)
    {
        std::cin>>pair.first>>pair.second;
    }

    int start = 0, end = 0;

    for(const auto& pair: schedule)
    {
        start = pair.first;
        end = pair.second;

        // 最短路径
        std::vector<int> minDst(N+1, INF);

        minDst[start] = 0;

        // V-1次松弛
        for(int i=0; i<N-1; ++i)
        {
            for(const auto& e: edges)
            {
                // 由于是无向图，所以松弛是双向的
                if(minDst[e.u]!=INF && minDst[e.v]>minDst[e.u]+e.w)
                {
                    minDst[e.v] = minDst[e.u] + e.w;
                }
                if(minDst[e.v]!=INF && minDst[e.u]>minDst[e.v]+e.w)
                {
                    minDst[e.u] = minDst[e.v] + e.w;
                }
            }
        }

        if(minDst[end]==INF)
        {
            std::cout<<-1<<std::endl;
        }else {
            std::cout<<minDst[end]<<std::endl;
        }
    }
    return 0;
}